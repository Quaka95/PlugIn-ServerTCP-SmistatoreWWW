/*FOR COMPILE: clear; g++ main.cpp -Wno-format-security -Wno-write-strings -std=c++11*/
#define MAX_BUFFER 4096

#include <iostream>
using namespace std;

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "errore.h"
#include "Socket.hpp"
#include "Address.hpp"
#include "List.hpp"
#include "TCP.hpp"

int main(int argc, char const *argv[])
{
	char* msgrec = "";
	char* msg = "HTTP/1.1 404 OK\n\
Date: Mon, 23 May 2005 22:38:34 GMT\n\
Server: Apache/1.3.3.7 (Unix) (Red-Hat/Linux)\n\
Last-Modified: Wed, 08 Jan 2003 23:11:55 GMT\n\
ETag: \"3f80f-1b6-3e1cb03b\"\n\
Content-Type: text/html; charset=UTF-8\n\
Content-Length: 131\n\
Accept-Ranges: bytes\n\
Connection: close";

	int server_port;

	if (argc !=2) {	
		printf("USAGE:%s PORT\n",argv[0]);
		return -1; 
	}

	server_port = atoi(argv[1]);

	Address* addr = new Address("127.0.0.1",server_port);
	ServerTCP* server = new ServerTCP(server_port);
	Conn_Server* client;

	client = server->accetta(addr);

	msgrec = client->ricevi();

	printf("%s\n",msgrec );

	client->invia(msg);

	printf("%s\n\n\n",msg);

	delete(addr);
	delete(server);
	delete(client);
	return 0;
}
