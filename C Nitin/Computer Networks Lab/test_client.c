#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define RECVBUFFERSIZE 255

void dieWithError(char *msg){
    perror(msg);
    exit(1);
}
long get_time_in_ms(){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000000 + ts.tv_nsec / 1000;
}
void main(int argc, char *argv[]){
    int iter = 0;
    int sock, servPort, bytesSent, byteRecvd;
    struct sockaddr_in echoServAddr;
    char *servIP, *echoString;
    char recvBuffer[RECVBUFFERSIZE];
    long startTime, endTime;
    if(argc < 3 || argc > 4){
        printf("\n");
        printf("Usage: %s <Server Address> <Echo String> <(optional) Port>\n", argv[0]);
        exit(0);
    }
    servIP = argv[1]; 
    echoString = argv[2];
    if(argc == 4)
        servPort = atoi(argv[3]);
    else
        servPort = 8080;
    if((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        dieWithError("socket() failed !");
    memset(&echoServAddr, 0, sizeof(echoServAddr));
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_addr.s_addr = inet_addr(servIP);
    echoServAddr.sin_port = htons(servPort);
    if(connect(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0)
        dieWithError("connect() failed !");
    while(1){
        if(iter == 0) printf("\nsending...");
        else{
        printf("\nEnter the string to send to the server (or \"exit\"): ");
        scanf("%s", echoString);
        printf("\nsending...");
        }
        if(strcmp(echoString, "exit") == 0) break;
        if((bytesSent = (send(sock, echoString, strlen(echoString), 0))) != strlen(echoString))
            dieWithError("send() sent unknown number of bytes !");
        startTime = get_time_in_ms();
        if((byteRecvd = (recv(sock, recvBuffer, RECVBUFFERSIZE, 0))) <= 0)
            dieWithError("recv() failed !");
        endTime = get_time_in_ms();
        recvBuffer[strlen(echoString)] = '\0';
        printf("\necho server echoed: %s", recvBuffer);
        printf("\nRTT: %ld", endTime - startTime);
        memset(recvBuffer, 0, RECVBUFFERSIZE);
        iter++;
    }
    close(sock);
    printf("connection to the server closed successfully !");
}