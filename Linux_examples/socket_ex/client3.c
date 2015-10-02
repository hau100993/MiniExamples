#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>


int main ( int argc, char *agr[]) {
	int sock, server_len;
	struct sockaddr_in server;
	char message[1000], server_reply[2000];

	// Create socket
	sock =socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		printf(" Could not create socket") ;
	}
	puts("Socket created") ;

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port =htons (8888);
	server_len =sizeof (server);
	// Connect to remote server

	if(connect(sock, (struct sockaddr *) &server, server_len) <0 ) {
		perror (" Connect: Failed ");
		return 1;
	}
	puts(" Connected") ;

	while(1) {
		printf(" Enter message: ");
		scanf (" %s", message);

		//sent some data :
		if (send(sock, message, strlen(message), 0) <0) {
			puts(" Send: Failed");
			return 1;
		}

		if (recv(sock, server_reply, 2000, 0) <0) {
			puts ("Recv: Failed");
			return 1;
		}
		puts("Server reply : ");
		puts( server_reply);
	}
	close(sock);
	return 0;

}
