#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char * arg[]) {

	int socket_desc, client_sock, c, read_size;
	struct sockaddr_in server, client;
	char *client_message;

	// creat socket

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);


	if (socket_desc == -1) {
		printf(" Failed to create Socket !");
	}
	puts("Successful creating Socket !");

	// prepare for sockaddr_in structe
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);

	//Bind
	if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
		perror("Failed Socket binding. Recheck !");
		return 1;
	}
	puts(" Bind Done !");

	listen(socket_desc, 3);
	puts("Waiting for incoming connections......");

	if (client_sock < 0) {
		perror("Accept: Failed");
		return 1;
	}
	while((client_sock=accept(socket_desc, (struct sockaddr *) &client, (socklen_t *)&c))) {

	puts(" Accept: Success ");

	//Receive a message from Client

//while((read_size = recv(client_sock, client_message, 200, 0)) >0)

	client_message = "Hello Client, I have received your connection ! Bye....^ ^ ! \n" ;
	write(client_sock, client_message, strlen(client_message));
}
if(read_size == 0) {
	puts(" Client disconnected") ;
	fflush(stdout);
}
else if (read_size == -1) {
perror ("Recv Failed");
}
return 0;

}
