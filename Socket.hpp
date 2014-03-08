#ifndef SOCKET_HPP
#define SOCKET_HPP

#define MAX_MSG 4096
#define COMMON_ADDR "0.0.0.0"
#define MAX_CONN 42

class Socket
{
	private:	
		int sock_id;
		SocketLogWriter log;
	public:
		
				
		Socket(int mode, char* path){
			log = new SocketLogWriter(path);
			sock_id=socket(AF_INET,mode,0);
			if(sock_id<0) {log.write("Socket Non Creato");
			 	errore("Errore Socket Server",-1);
			 }
			log.write("Socket Creato con Successo");
		}
		~Socket(){ 
			shutdown(sock_id, SHUT_RDWR);
		}
		int get_sock_id(){
			return sock_id;
		}
		
		void WriteLog(char* stringa)
		{
			log.write(stringa);
		}
};

#endif
