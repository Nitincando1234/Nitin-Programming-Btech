#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define ECHOMAX 255
void dieWithError(char *errMsg){
    perror(errMsg);
    exit(1);
}
int main(int argc, char *argv[]){
    int sock;
    struct sockaddr_in echoServAddr;
    struct sockaddr_in echoClntAddr;
    unsigned short echoServPort;
    unsigned int cliAddrLength;     // for the incoming message's length at buffer
    char cliBuffer[ECHOMAX];
    int recvMsgSize;                // Length of the recieved message 

    if(argc != 2){
        printf("Usage: %s <UDP server port>", argv[0]); 
        exit(0);
    }
    echoServPort = atoi(argv[1]);
    if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    dieWithError("socket() failed !");
    memset(&echoServAddr, 0, sizeof(echoServAddr));
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    echoServAddr.sin_port = htons(echoServPort);

    if((bind(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr))) < 0)
        dieWithError("bind() failed !");
    for(;;){
        cliAddrLength = sizeof(echoClntAddr);
        if((recvMsgSize = recvfrom(sock, cliBuffer, ECHOMAX, 0, (struct sockaddr *) &echoClntAddr, &cliAddrLength)) < 0)
            dieWithError("recvfrom() failed !");
        printf("Handling client %s\n", inet_ntoa(echoClntAddr.sin_addr));
        // send back to the client
        if((sendto(sock, cliBuffer, recvMsgSize, 0, (struct sockaddr *) &echoClntAddr, sizeof(echoClntAddr))) != recvMsgSize)
            dieWithError("sendto() failed !");
    }
    // Never reached
}