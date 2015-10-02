#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <arpa/inet.h>	// inet_addr
#include <unistd.h>		//write
#include <pthread.h>

void *connection_handler(void *);

int main(int argc, char *agrv[]) {
	int socket_desc, new_socket, c;
	int *new_sock;
	struct sockaddr_in server, client;
	char *message;

	// Create Socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1) {
		puts(" Create Socket: Failed !");
	}

	// Prepare the socketaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(9999);

	if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server))) {
		puts(" Bind Socket: Failed");
	}
	puts(" Bind Socket : Success");

	//listen
	listen(socket_desc, 3);
	puts(" Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);

	while ((new_socket = accept(socket_desc, (struct sockaddr *) &client,
			(socklen_t*) &c))) {
		puts(" Connect to Socket: Success \n ");
		message =
				" Hello Client, I received your connection, I will assign a handler for you\n";
		write(new_socket, message, strlen(message));

		// Create a thread to handler
		pthread_t sniffer_thread;
		new_sock = malloc(1);
		*new_sock = new_socket;
		if (pthread_create(&sniffer_thread, NULL, connection_handler,
				(void*) new_sock) < 0) {
			perror("Could not create thread ");
			return 1;
		}
		puts(" Handler assigned ");
	}
	if (new_socket < 0) {
		perror("Accept Failed");
		return 1;
	}
	return 0;
}

void *connection_handler(void *socket_desc) {
	int sock = *(int *) socket_desc;
	char * message;
	char client_mesg[2000];
	int read_size;
	//send some message to the client
//	message = "Greeting ! I am your connection handler \n" ;
	write(sock, "Greeting ! I am your connection handler :)\n",
			strlen("Greeting ! I am your connection handler :) \n"));

	while ((read_size = recv(sock, client_mesg, 2000, 0) > 0)) {
		write(sock, client_mesg, strlen(client_mesg));
	}
	if (read_size == 0) {
		puts("Client disconnected");
		fflush(stdout);
	} else if (read_size == 0) {
		puts(" Client disconnected !");
	} else if (read_size == -1) {
		perror(" Rev : Failed");
	}
	free(socket_desc);
	return 0;

}
