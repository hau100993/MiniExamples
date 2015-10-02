#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>

//unsigned long int htonl(unsigned long int hostlong);
//unsigned short int htons(unsigned short int hostshort);
//unsigned long int ntohl(unsigned long int netlong);
//unsigned short int ntohs(unsigned short int netshort);

int main() {

	int sockfd;
	int len;
	struct sockaddr_in address;
	int result;
	char ch = 'A';
	printf("Initializing....");
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf (" Create Socket: Failed");
	}
	puts(" Create Socket: Success");


	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htonl(8888);

	len = sizeof(address);

	result = connect(sockfd, (struct sockaddr *) &address, len);

	if (result < 0) {
		perror("Opps: client2 !");
		exit(1);
	}

	puts(" Connected") ;

while(1) {
	write(sockfd, &ch, 1);
	read(sockfd, &ch, 1);

	printf("Char read from server = %c \n", ch);
	close(sockfd);
}
	exit(0);
}

