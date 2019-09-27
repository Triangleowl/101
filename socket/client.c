/*
 *Date: 2019-09-27
 *function: 作为client，向server发送数据
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main()
{
    struct sockaddr_in ser_sock;
    char buf[1024];
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&ser_sock, 0, sizeof(ser_sock));
    ser_sock.sin_family = AF_INET;
    ser_sock.sin_addr.s_addr = inet_addr("127.0.0.1");
    ser_sock.sin_port = htons(8888);

    connect(sock_fd, (struct sockaddr *)&ser_sock, sizeof(ser_sock));

    while(1){

        memset(buf, 0, BUF_SIZE);
        read(0, buf, BUF_SIZE);
        write(sock_fd, buf, BUF_SIZE);
    }
    
    return 0;
}

