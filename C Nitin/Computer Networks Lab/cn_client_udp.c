#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define ECHOMAX 255

void dieWithError(char * errMsg){
    perror(errMsg);
    exit(1);
}
long get_time_in_microsecond(){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 10000 + ts.tv_nsec / 1000;
}
int main(int argc, char *argv[]){
    int sock;
    struct sockaddr_in fromAddr, echoServAddr;
    unsigned int echoServPort, fromSize;    
    char *echoServIP, *echoString;
    char echoBuffer[ECHOMAX];
    int echoStringLen, recvdDataLen;
    long startTime, endTime;

    if((argc > 4) || (argc < 3)){
        fprintf(stderr, "Usage: %s <server IP> <echo string> [<port>]\n", argv[0]);
        exit(0);
    }
    echoServIP = argv[1];
    echoString = argv[2];
    if((echoStringLen = strlen(echoString)) > ECHOMAX)
        dieWithError("\nEcho Word is too long !");
    if(argc == 4)
        echoServPort = atoi(argv[3]);
    else
        echoServPort = 8080;
    
    if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        dieWithError("\nsocket() failed !\n");
    
    // Server Structure setup
    memset(&echoServAddr, 0, sizeof(echoServAddr));
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_port = htons(echoServPort);
    echoServAddr.sin_addr.s_addr = inet_addr(echoServIP);

    startTime = get_time_in_microsecond();
    if(sendto(sock, echoString, echoStringLen, 0,(struct sockaddr*) &echoServAddr, sizeof(echoServAddr)) != echoStringLen)
        dieWithError("send() sent unknown amount of data !\n");
    fromSize = sizeof(fromAddr);
    if((recvdDataLen = recvfrom(sock, echoBuffer, ECHOMAX, 0, (struct sockaddr*) &fromAddr, &fromSize)) < 0)
        dieWithError("recv() failed !\n");
    endTime = get_time_in_microsecond();

    if(echoServAddr.sin_addr.s_addr != fromAddr.sin_addr.s_addr)
        dieWithError("Client recieved the echo from UNK server !\n");
    
    echoBuffer[recvdDataLen] = '\0';
    printf("\nThe data recieved from the server: %s", echoBuffer);

    close(sock);
    printf("\nRTT: %ld microseconds\n", endTime - startTime);
    printf("\nSocket closed for any i/o data successfully !\n");
    exit(0);
}