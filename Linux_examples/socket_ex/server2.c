//#include <sys/types.h>
//#include <sys/socket.h>
//#include <unistd.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <stdlib.h>
//#include <stdio.h>


#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

//unsigned long int htonl(unsigned long int hostlong);
//unsigned short int htons(unsigned short int hostshort);
//unsigned long int ntohl(unsigned long int netlong);
//unsigned short int ntohs(unsigned short int netshort);

int main() {

	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;

	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_sockfd == -1) {
		printf(" Create Socket: Failed !");
	}

	puts(" Create_Socket: Success ");

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htonl(8888);

	server_len = sizeof(server_address);

	if (bind(server_sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
		printf(" Bind Socket: Failed !");
	}
	puts(" Bind Socket: Success ");

	listen(server_sockfd, 3);
	puts(" Waiting for connections......");
	client_len = sizeof(client_address);
	if ((client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_address,&client_len)) <0 )  {
		perror("Accept: Failed");
	}

	puts(" Accept: Success ");

	while (1) {
		char ch;
		printf("server_waiting");
//		client_len = sizeof(client_address);
//		client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_address, &client_len);

		read(client_sockfd, &ch, 1);
		ch++;
		write(client_sockfd, &ch, 1);
		close(client_sockfd);
	}

}
