#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define MAXPENDING 5
#define RCVBUFFER 32    // size of the recieving buffer size from the client -> server

void dieWithError(char *errMsg){
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
    int *servSock;      // socket descriptors list for server
    int maxDescriptor = -1;      // Max socket descriptor value
    fd_set sockSet;
    long timeout;
    struct timeval selTimeout;
    int running = 1;
    int noPorts;
    int port;
    unsigned short portNo;
    struct sockaddr_in echoServAddr;
    struct sockaddr_in echoClntAddr;
    unsigned int clntLen;
    if(argc < 3){
        fprintf(stderr, "Usage: %s <Timeout (secs)> <Port1> ...*\n", argv[0]);
        exit(1);
    }
    timeout = atol(argv[1]);
    noPorts = argc - 2;
    servSock = (int *) malloc(noPorts * sizeof(int));
    
    for(port = 0; port < noPorts; port++){
        portNo = atoi(argv[port + 2]);
        // create the socket for the pocket
        if((servSock[port] = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        dieWithError("socket() failed !");
        
        memset(&echoServAddr, 0, sizeof(echoServAddr));
        echoServAddr.sin_family = AF_INET;
        echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        echoServAddr.sin_port = htons(portNo);

        if((bind(servSock[port], (struct sockaddr *) &echoServAddr, sizeof(echoServAddr))) < 0)
        dieWithError("bind() failed !");

        // start listening on the socket
        if((listen(servSock[port], MAXPENDING)) < 0)
        dieWithError("listen() failed !");

        if(servSock[port] > maxDescriptor)
            maxDescriptor = servSock[port];
    }
    printf("Starting server: Hit return to shutdown\n");
    while(running){
        FD_ZERO(&sockSet);     // removes all vectors/descriptors from fd_set
        FD_SET(STDIN_FILENO, &sockSet);
        for(port = 0; port < noPorts; port++)
            FD_SET(servSock[port], &sockSet);
        selTimeout.tv_sec = timeout;
        selTimeout.tv_usec = 0;

        if(select(maxDescriptor + 1, &sockSet, NULL, NULL, &selTimeout) == 0)
            printf("No request from client for %ld secs...Server will still alive\n", timeout);
        else{
            if(FD_ISSET(STDIN_FILENO, &sockSet)){       // check the keyboard
                printf("Shutting down the server\n");
                running = 0;
            }
            for(port = 0; port < noPorts; port++){
                if FD_ISSET(servSock[port], &sockSet){
                int clntSock = accept(servSock[port], (struct sockaddr *)&echoClntAddr, &clntLen);
                printf("Handling client on port: %d\n", port);
                handleClient(clntSock);
                }
            }
        }
    }
    printf("Closing the sockets !");
    for(port = 0; port < noPorts; port++)
        close(servSock[port]);
    free(servSock);
    exit(0);
}
