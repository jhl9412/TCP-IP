#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char **argv)
{
	int serv_sock;
	int clnt_sock;
	int c=0;
//server 에서는 socket이 2개 만들어진다.
	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;
	for(int i=0; i<10; i++)
	{
		c++;
	}

	char message[]="Hello World!";
// port 미기입시 error handling.
	if(argc!=2)
	{
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
// socket 생성.	
	serv_sock=socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock == -1)
		error_handling("socket() error");
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;//domain 방식- PF : PROTOCOL, AF:ADDRESS 
	// PF,AF 가 똑같이 정의되어 있다.
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);//host to network long (4byte)
	serv_addr.sin_port=htons(atoi(argv[1]));	//htons short(2byte)
	//inaddr_any : 자동 할당.
	// option - bind error handle
	int option =1;
	socklen_t optlen;
	optlen = sizeof(option);
	setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, (void*)&option, optlen);

// bind ip_addr, port 할당.
	if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1)
		error_handling("bind() error");
// 구조체 형변환 : sockaddr_in 은 ipv4로 만들어진 것. original 은 sockaddr이라 형변환
// 크기는 똑같지만 멤버가 다름. sockaddr 은 다양한 주소 체계를 모두 사용할 수 있다.
// listen 	
	if(listen(serv_sock, 5)==-1)
		error_handling("accept() error");
// accept - while(연결요청이 있을때까지)->clnt_sock 생성.	
	clnt_addr_size=sizeof(clnt_addr);
	clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
	if(clnt_sock==-1)
		error_handling("accept() error");

	write(clnt_sock, message, sizeof(message));
	close(clnt_sock);
	close(serv_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
