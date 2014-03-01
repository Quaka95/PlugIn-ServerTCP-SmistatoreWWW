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
	ClientTCP* client = new ClientTCP();
	ServerTCP* server = new ServerTCP(SERVER_PORT);
	Conn_Server* conn;

	conn=server->accetta();
	client->connetti();
	client->invia("Ciao Mario",addr);
	msg = conn->ricevi(addr);

	cout << msg << endl;

	delete(addr);
	delete(client);
	delete(server);
	delete(conn);
	return 0;
}
