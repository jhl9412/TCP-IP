#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 100
void error_handling(char *message);

int main(int argc, char **argv)
{
	int sock;
	struct sockaddr_in serv_addr;
	char message[BUF_SIZE];
	int str_len;
	
	int fd;

	if(argc!=3)
	{
	printf("Usage : %s <IP> <port><\n", argv[0]);
	}
	
	sock=socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port=htons(atoi(argv[2]));

	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
		error_handling("connect() error!");
	
	do {
		str_len = read(fd, message, sizeof(message));
		if(str_len > 0)
		{
			str_len = write(sock,message, str_len);
			if(str_len <0)
				error_handling("write() error!");
			else if(str_len == 0)
				break;
		}
		else if(str_len == 0)
			break;
		else
			error_handling("read() error!");
	} while(1);

	printf("Message from server : %s \n", message);
	close(fd);
	close(sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n',stderr);
	exit(1);
}
