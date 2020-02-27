#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
int main(){
	int opt = 1, new_socket, valread, socket_fd;
	char buffer[1024] = {0};
	char* hello = "hello form server";
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8080);
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
 	bind(socket_fd, (struct sockaddr*)&address, sizeof(address));
	listen(socket_fd, 3);
	printf("listensing\n");
	new_socket = accept(socket_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
	printf("acc\n");
	valread = read(new_socket, buffer, 1024);
	printf("%s\n", buffer);
	send(new_socket, hello, strlen(hello), 0);
	send(new_socket, hello, strlen(hello), 0);

	return 0;

}
