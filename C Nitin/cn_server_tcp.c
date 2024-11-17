#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#define MAXPENDING 5
#define RCVBUFFER 32    // size of the recieving buffer size from the client -> server

void dieWithError(char * errMsg){
    perror(errMsg);
    exit(1);
}
void handleClient(int clntSocket){
    char rcvBuffer[RCVBUFFER];
    int recvMsgSize;

    if((recvMsgSize = recv(clntSocket, rcvBuffer, RCVBUFFER, 0)) < 0)
    dieWithError("recv() failed !");

    while(recvMsgSize > 0){      // 0 => mean end of transmission
        // send back to the client socket working as an echoing server
        if((send(clntSocket, rcvBuffer, recvMsgSize, 0)) != recvMsgSize)
        dieWithError("send() sent to the client an unexpected data !");

        // if client socket sends more data iterate through the loop
        if((recvMsgSize = recv(clntSocket, rcvBuffer, RCVBUFFER, 0)) < 0)
        dieWithError("recv() failed !");
    }
}

int main(int argc, char *argv[]){
    int servSock, clntSock;
    struct sockaddr_in echoServAddr;    // local server address
    struct sockaddr_in echoClntAddr;     // address of the client
    unsigned short echoServPort;
    unsigned int clntLen;               // length of the client address structure

    if(argc != 2){
        fprintf(stderr, "Usage: %s <Port>\n", argv[0]);
        exit(1);
    } 

    echoServPort = atoi(argv[1]);
    if((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    dieWithError("socket() failed !");

    memset(&echoServAddr, 0, sizeof(echoServAddr));
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    echoServAddr.sin_port = htons(echoServPort);

    if((bind(servSock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr))) < 0)
    dieWithError("bind() failed !");

    // start listening on the socket
    if((listen(servSock, MAXPENDING)) < 0)
    dieWithError("listen() failed !");

    for(;;){    // loops forever
    clntLen = sizeof(echoClntAddr);
    if((clntSock = accept(servSock, (struct sockaddr *) &echoClntAddr, &clntLen)) < 0)
    dieWithError("accept() failed !");

    printf("Handling client: %s\n", inet_ntoa(echoClntAddr.sin_addr));   // converts the int value of the echoClntAddr back to the quad dotted format
    handleClient(clntSock);
    }
}