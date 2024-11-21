#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define RCVBUFSIZE 32

void dieWithError(char * errMsg){
    perror(errMsg);
    exit(1);
}

int main(int argc, char *argv[]){
    int sock;   // socket descriptor
    struct sockaddr_in echoServAddr;
    unsigned short echoServPort;
    char *echoString;
    char *servIP;
    char echoBuffer[RCVBUFSIZE];
    unsigned int echoStringLen;
    int bytesRcvd, totalBytesRcvd;
    if((argc < 3) || (argc > 4)){
        fprintf(stderr, "Usage: %s <ServIP> <echoStr> <Port(optional)>\n", argv[0]);
        exit(1);
    }
    servIP = argv[1];
    echoString = argv[2];
    if(argc == 4)
    echoServPort = atoi(argv[3]);
    else
    echoServPort = 8080;   // well-defined port number to recieve back the echoed string for debugging purposes

    if((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    dieWithError("Socket() failed !");
    
    //zero out the structure & set the components of it
    memset(&echoServAddr, 0, sizeof(echoServAddr));
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_addr.s_addr = inet_addr(servIP);
    echoServAddr.sin_port = htons(echoServPort);

    if((connect(sock,(struct sockaddr *) (&echoServAddr), sizeof(echoServAddr))) < 0)        // connect to the server at echoServAddr and create i/o type sock descriptor
    dieWithError("connect() failed !");
    echoStringLen = strlen(echoString);
    if(send(sock, echoString, echoStringLen, 0) != echoStringLen)
    dieWithError("send() sent the data of lenght that is unexpected !");

    totalBytesRcvd = 0;
    printf("Recieved :\n");
    while(totalBytesRcvd < echoStringLen){
    if((bytesRcvd = (recv(sock, echoBuffer, RCVBUFSIZE - 1, 0))) <= 0)
    dieWithError("recv() failed or closed the connection permanently !");

    totalBytesRcvd += bytesRcvd;
    echoBuffer[bytesRcvd] = '\0';
    printf("%s", echoBuffer);
    }

    close(sock);
    printf("\nCode completed Succesfully !\n");
}