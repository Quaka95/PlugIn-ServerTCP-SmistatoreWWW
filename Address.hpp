#ifndef ADDRESS_HPP
#define ADDRESS_HPP

typedef struct sockaddr_in Addr_bin;

class Address {
	private: 
		char* 	ip;
		int 	port;

	public: 
		//Builder
		Address();

		Address(char* _ip, int _port);

		Address(Addr_bin* _addr);

		//Accessors
		char* 	get_ip();
		int 	get_port();
		void	set_ip(char* _ip);
		void 	set_port(int _port);
		void 	show();
		void 	set_addr( Addr_bin* _addr);
		Addr_bin* get_addr();

		//Destructor
		~Address();
};

/*#########################################################################################*/

	//Builder
	Address::Address():Address("0.0.0.0",0) { }

	Address::Address(char* _ip, int _port){
		ip = strdup(_ip);
		port = _port;
	}

	Address::Address(Addr_bin* _addr){
		ip=strdup(inet_ntoa(_addr->sin_addr));
		port = ntohs(_addr->sin_port);
	}

	//Accessors
	char* 	Address::get_ip() { return strdup(ip); }

	int 	Address::get_port() { return port; }

	void	Address::set_ip(char* _ip) {
		free(ip);
		ip = strdup(_ip);
	}

	void 	Address::set_port(int _port) { port=_port; }

	void 	Address::show(){
		cout << "addr:" << ip << ":" << port << endl;
	}

	//Fake Accessors
	void 	Address::set_addr( Addr_bin* _addr){
		free(ip);
		ip=strdup(inet_ntoa(_addr->sin_addr));
		port = ntohs(_addr->sin_port);
	}

	Addr_bin* Address::get_addr(){
		Addr_bin* ret;
		ret = (Addr_bin*) malloc(sizeof(Addr_bin));
		ret->sin_family = AF_INET;
		inet_aton(ip,&(ret->sin_addr));
		ret->sin_port= htons(port);
		for (int i=0;i<8;i++) { ret->sin_zero[i]=0; }
		return ret;
	}

	//Destructor
	Address::~Address() { free(ip); }

/*#########################################################################################*/

#endif 
