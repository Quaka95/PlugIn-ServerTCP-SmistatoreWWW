#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "errore.h"
#include "Socket.hpp"
#include "Address.hpp"
#include "TCP.hpp"

#define SERVER_PORT 9000

int main(int argc, char const *argv[])
{
	char* msg = "ERRORE";

	Address* addr = new Address("127.0.0.1",SERVER_PORT);
	ServerTCP* server = new ServerTCP(SERVER_PORT);
	Conn_Server* client;

	client = server->accetta(NULL)


	return 0;
}
