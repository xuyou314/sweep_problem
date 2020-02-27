#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int main(){
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char* msg = "hello from client";
	char buffer[1024] ={0};
	char buffer2[1024] ={0};
	sock = socket(AF_INET, SOCK_STREAM, 0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(8080);
	inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
	connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	send(sock, msg, strlen(msg), 0);
	valread = read(sock, buffer, 1024);
	printf("%s\n", buffer);
	valread = read(sock, buffer2, 1024);
	printf("%s\n", buffer2);
	return 0;
}
