#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<arpa/inet.h>

#define SERVER_ADD "127.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1000

long get_time_in_microsecond(){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 10000 + ts.tv_nsec / 1000;
}
int main(){
    int client_socket, bytes_recieved, len;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE], message[BUFFER_SIZE];
    long time_in_ms, end_time_in_ms; 

    if((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket() failed !");
        exit(1);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if((inet_pton(AF_INET, SERVER_ADD, &server_address.sin_addr)) <= 0){
        perror("inet_ptons() failed !");
        exit(1);
    }
    
    if(connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0){
        perror("connect() failed !");
        exit(1);
    }
    printf("Connection to server has been established !");

    while(1){
        printf("\nEnter the message(\"exit\" to quit): ");
        fgets(message, BUFFER_SIZE, stdin);
        len = strlen(message);
        if(len > 0 && message[len - 1] == '\n')
            message[len - 1] = '\0';
        if(strcmp(message, "exit") == 0)
            break;
        
        send(client_socket, message, len, 0);
        time_in_ms = get_time_in_microsecond();
        bytes_recieved = recv(client_socket, buffer, BUFFER_SIZE, 0);
        end_time_in_ms = get_time_in_microsecond();
        buffer[bytes_recieved] = '\0';
        printf("\nEcho Server echoed: %s", buffer);
        printf("\nRTT is: %ld microseconds", end_time_in_ms - time_in_ms);
    }
    close(client_socket);
    printf("Connection to server has been closed !\n");
}