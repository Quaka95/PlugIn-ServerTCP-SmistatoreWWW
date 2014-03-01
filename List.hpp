#ifndef LIST_HPP
#define LIST_HPP

class Nodo
{
	private:
		Nodo* _next;
	public:
		Nodo():Nodo(NULL){}
		Nodo(Nodo* next){
			set_next(mext);
		}
		~Nodo();
		void	set_next(Nodo* next){
			_next=next;
		}
		Nodo*	get_next(){
			return _next;
		}
};

class Iterator;	//Uso lista dentro iterator

class Lista
{
private:
	Nodo* _first;
	void remove_Nodo(Nodo* curr) {
		if(curr){
			remove_Nodo(curr->get_next());
			delete(curr);
		}
	};
public:
	Lista(Nodo* first){
		add_Node(first);
	}
	~Lista() { remove_Nodo(first); 	};
	Nodo* add_Node(Nodo* add){
		add->set_next(_first);
		_first = add;
	}
	Iterator* create_Iterator(){
		return new Iterator(this);
	}
	Nodo* get_first(){
		return _first;
	}
};

class Iterator
{
private:
	Lista* _lista;
	Nodo* _current;
public:
	Iterator(Lista* lista){
		_lista = lista;
		_current=_lista->getFirst();
	}
	~Iterator(){}

	Nodo* get_current(){
		return _current;
	}
	Nodo* move_next(){
		if(_current){
			_current=_current->get_next();
		}
		return get_current();
	}
	Nodo* move_first(){
		if(_lista){
			_current=_lista->get_first();
		}
		return get_current();
	}
	bool is_done(){
		return !(_current->get_next());
	}
};

#endif
