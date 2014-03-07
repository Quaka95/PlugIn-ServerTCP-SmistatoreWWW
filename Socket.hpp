#ifndef SOCKET_HPP
#define SOCKET_HPP

#define MAX_MSG 4096
#define COMMON_ADDR "0.0.0.0"
#define MAX_CONN 42

class Socket
{
	private:	
		int sock_id;
	public:		
		Socket(int mode){	//socket()
			sock_id=socket(AF_INET,mode,0);
			if(sock_id<0) { errore("Errore Socket Server",-1); }
		}
		~Socket(){ //shutdown
			shutdown(sock_id, SHUT_RDWR);
			close(sock_id);
		}
		int get_sock_id(){
			return sock_id;
		}
};

#endif
