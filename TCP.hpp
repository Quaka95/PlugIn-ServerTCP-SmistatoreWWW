#ifndef TCP_HPP
#define TCP_HPP


class SocketTCP: public Socket
{
	private:
	public:
		SocketTCP() : Socket(SOCK_STREAM,"./log.txt"){
		}
		~ SocketTCP(){
		}
};

class Connessione : public Nodo
{
	protected:
		int _conn_id;
	public:
		Connessione(int conn_id, Nodo* next=NULL):Nodo(next){
			_conn_id=conn_id;
		}
		~Connessione(){}
		bool	invia(char* msg){	//send()
			int len_msg;
			int ret;

			len_msg = strlen(msg)+1;
			ret = send(_conn_id,msg,len_msg,0);
			if (ret==len_msg)
			{
				char* str = "\"";
				str = strcat(str,msg);
				str = strcat(str,"\" Inviato alla connessione: ");
				str = strcat(str,(char*)_conn_id); 
				WriteLog(str);
			}
			else
			{
				WriteLog("Errore nell'invio");
			}
			return (ret==len_msg);
		}
		char*	ricevi(){	//recv()
			char buffer[MAX_BUFFER+1];
			int ret;

			ret = recv(_conn_id,buffer,MAX_BUFFER,0);

			if(ret<1){
				WriteLog("Impossibile ricevere");
				return NULL;
			}

			buffer[ret]='\0';
			char* str = "\"";
			str = strcat(str,strdup(buffer));
			str = strcat(str,"\" Ricevuto da");
			WriteLog(str);
			return strdup(buffer);
		}
};

class Conn_Client : public Connessione
{
public:
	Conn_Client(int sock_id) : Connessione(sock_id){
	}
	~Conn_Client();	//Niente
};

class Conn_Server : public Connessione
{
public:
	Conn_Server(int conn_id):Connessione(conn_id){}
	~Conn_Server(){	//Close
		close(Connessione::_conn_id);
	}	
};

class ClientTCP : public SocketTCP
{
	private:
		Conn_Client* connessione;
	public:
		ClientTCP(){}
		~ ClientTCP(){}
		Conn_Client*	connetti(Address* server){	//connect()
			int ret;
			ret=connect(get_sock_id(),(struct sockaddr*) server->get_addr(),(socklen_t)sizeof(struct sockaddr));
			if(ret){ return NULL; }
			connessione = new Conn_Client(get_sock_id());
			return connessione;
		}
		bool	close_con() {
			delete(connessione);
			char* str = "Chiusa la connessione ";
			str = strcat(str, char* connessione->_get_conn_id);
			WriteLog(str);
		}
		bool	invia(char* msg) { return connessione->invia(msg); };
		char*	ricevi() { return connessione->ricevi(); };
};

class ServerTCP : SocketTCP
{
	private:
		Lista* lista_connessione;
	public:
		ServerTCP(int port){	//bind() - listen()
			int ret;
			lista_connessione = new Lista();
			Address* mySelf;
			
			mySelf = new Address(COMMON_ADDR,port);
			ret = bind(get_sock_id(),(struct sockaddr*)mySelf->get_addr(),(socklen_t)sizeof(struct sockaddr));
			if(ret){
				errore("SocketTCP - Errore nell'assegnazione della porta\n",-1);
			}

			ret = listen(get_sock_id(), MAX_CONN);

			if(ret){
				errore("Errore nell'assegnazioen nel numero di connessioni\n",-3);
			}

			delete(mySelf);
		}

		~ServerTCP(){
			delete(lista_connessione);
		}

		Conn_Server*	accetta(Address* client){ //accept()
			Conn_Server* conn;
			int id;
			int len_addr;

			len_addr = sizeof(struct sockaddr_in);
			id = accept(get_sock_id(), (struct sockaddr*) client->get_addr(),(socklen_t*) &len_addr);

			if(id<=0){
				return NULL;
			}

			conn=new Conn_Server(id);

			lista_connessione->add_Nodo(conn);
			return conn;
		}	
		void close_tutte_connessioni(){
			Iterator* index = lista_connessione->create_Iterator();
			do{
				delete(index->get_current());
				index->move_next();
			}while(index->is_done());
		}
		void invia_a_tutti(char* msg){
			Iterator* index = lista_connessione->create_Iterator();
			do{
				((Conn_Server*)index->get_current())->invia(msg);
				index->move_next();
			}while(index->is_done());
		}

};

#endif
