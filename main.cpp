/*FOR COMPILE: clear; g++ main.cpp -Wno-format-security -Wno-write-strings -std=c++11*/
#define MAX_BUFFER 4096
#define SERVER_PORT 9000

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
	char* msg = "ERRORE";

	Address* addr = new Address("127.0.0.1",SERVER_PORT);
	ServerTCP* server = new ServerTCP(SERVER_PORT);
	Conn_Server* client;

	client = server->accetta(NULL);


	return 0;
}
