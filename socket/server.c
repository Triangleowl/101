/*
 * Date: 2019-09-27
 * function: 一个简单的socket编程示例，本文件作为server，创建socket
 *          等待client连接，然后将client发送的数据用printf打印出来，
 *          直到client结束
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
    struct sockaddr_in clt_sock;
    socklen_t sock_size;
    char buf[BUF_SIZE];
    int sock_clt_fd;
    int sock_ser_fd = socket(AF_INET, SOCK_STREAM, 0);
    if( sock_ser_fd < 0 ){
        perror("socket");
        return 1;
    }

    memset(&ser_sock, 0, sizeof(ser_sock));
    memset(&ser_sock, 0, sizeof(clt_sock));
    ser_sock.sin_family = AF_INET;
    ser_sock.sin_port = htons(8888);
    ser_sock.sin_addr.s_addr = inet_addr("127.0.0.1");
    bind(sock_ser_fd, (struct sockaddr *)&ser_sock, sizeof(ser_sock));

    listen(sock_ser_fd, 20);
    printf("listen....\n");

    sock_size = sizeof(ser_sock);
    sock_clt_fd = accept(sock_ser_fd, (struct sockaddr *)&ser_sock, &sock_size);
    printf("connected successfully!\n");

    while(1){
        memset(buf, 0, BUF_SIZE);
        read(sock_clt_fd, buf, BUF_SIZE);
        if( buf[0] == 0 ){
            goto disconnected;
        }
        printf("received: %s", buf);
    }

disconnected:
    printf("disconnected~!\n");
    close(sock_clt_fd);
    close(sock_ser_fd);
    
    return 0;
}

