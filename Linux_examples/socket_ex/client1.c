#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

// ---init ---
	int sockfd;
	int len;
	struct sockaddr_un address;
	int result;
	char ch = 'A';
	printf("Initializing....");
//---Create a socket for client ---
	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

//---Name the Socket as agreed with server---
	address.sun_family = AF_UNIX;
	strcpy(address.sun_path, "server_socket");
	len = sizeof(address);

//---Connect your Socket to severs's socket---

	result = connect(sockfd, (struct sockaddr *) &address, len);
	if (result == -1) {
		perror(" Error: Client1");
		exit(1);
	}
//--- Read and write via sockfd
	    write(sockfd, &ch, 1);
	//int i=0;
	//for(i=0;i<=10;i++) {
		read(sockfd, &ch, 1);
		printf(" Char read from server = %c \n", ch);
		//write(sockfd, &ch, 1);
	exit(0);

}

