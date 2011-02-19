#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define SERVER_PORT		20000
#define BUFFER_SIZE		20000

char buffer[BUFFER_SIZE];
void onerror(char * buf)
{
    perror(buf);
    exit(1);
}
int main(int argc, char *argv[])
{
	int i, n, len;
	int client_sock;
	socklen_t server_len;
	struct sockaddr_in server;
    int fd;
    char size_buf[4];
    int *size;

	if(argc < 4)
	{
		printf("\n");
		printf("Sorry, your type is wrong.\n");
		printf("Usage: %s x.x.x.x(server IP) filename\n", argv[0]);
		printf("\n");
		exit(EXIT_FAILURE);
	}

	if ((client_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        onerror("socket");
	else
		printf("create socket ok!\n");

	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);
	server.sin_addr.s_addr = inet_addr(argv[1]);

	server_len = sizeof(server);
	if(connect(client_sock, (struct sockaddr *)&server, server_len) < 0)
        onerror("connect");
	else
		printf("connect server ok!\n");
    n = send(client_sock, argv[2], strlen(argv[2]), 0);
    len = recv(client_sock, size_buf, 4, 0);
    size = (int *)size_buf;
    fd = open(argv[3], O_RDWR | O_CREAT, 00644);
    printf("%s size: %d bytes\n", argv[2], *size);
    for (i = 0; i < *size / BUFFER_SIZE + 1; i++) 
    {
        if(i == *size / BUFFER_SIZE)
        {
            len = recv(client_sock, buffer, *size % BUFFER_SIZE, 0);
            write(fd, buffer, len);
        }
        else
        {
            len = recv(client_sock, buffer, BUFFER_SIZE, 0);
            write(fd, buffer, len);
        }
    }
    
	close(client_sock);

	exit(EXIT_SUCCESS);
}
