#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SERVER_PORT		20000
#define BUFFER_SIZE     20000
char buffer[BUFFER_SIZE];

void onerror(char * buf)
{
    perror(buf);
    exit(1);
}
int main(int argc, const char *argv[])
{
    char c;
    int i, len, n;
    int server_sock, client_sock;
    socklen_t client_len;
    struct sockaddr_in server, client;
    struct in_addr in;
    int fd;
    struct stat buf;
    char size_buf[4];
    int *size;

    if( (server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
        onerror("socket");
    else
        printf("create socket OK!\n");
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    server.sin_addr.s_addr = htons(INADDR_ANY);

    if(bind(server_sock, (struct sockaddr *) &server, sizeof(server)) < 0)
        onerror("bind");
    else
        printf("bind address OK!\n");
    if(listen(server_sock, 5) < 0)
        onerror("listen");
    else
        printf("listen OK!\n");
    while(1)
    {
        client_len = sizeof(client);
        if( (client_sock = accept(server_sock, (struct sockaddr *)&client, &client_len )) < 0)
        {
            close(server_sock);
            onerror("accept");
        }
        else
        {
            printf("accept client OK!\n");
            in.s_addr = client.sin_addr.s_addr;
            printf("client ip: %s\n", inet_ntoa(in));
            printf("client port: %d\n",ntohs(client.sin_port));
        }

        len = recv(client_sock, buffer, 256, 0);
        printf("File to send:\n");
        write(STDOUT_FILENO, buffer, len);
        putchar('\n');
        fd = open(buffer, O_RDONLY);
        fstat(fd, &buf);
        size = (int *)size_buf;
        *size = buf.st_size;
        n = send(client_sock, size_buf, 4, 0);
        for (i = 0; i < *size / BUFFER_SIZE + 1; i++) 
        {
            if(i == *size / BUFFER_SIZE)
            {
                read(fd, buffer, *size % BUFFER_SIZE);
                send(client_sock, buffer, *size % BUFFER_SIZE, 0);
            }
            else
            {
                read(fd, buffer, BUFFER_SIZE);
                send(client_sock, buffer, BUFFER_SIZE, 0);
            }
            printf("%d\n",i);
        }
        printf("File send complete!\n");
        close(client_sock);
        printf("client close the connect, wait for new connect\n");
    }
    close(server_sock);
    return 0;
}
