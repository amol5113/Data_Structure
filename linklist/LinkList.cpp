#include <iostream>

using namespace std;

template <typename T> 

class Node{

	private:
		T data;
		Node *next;	
	public:
		Node(){ }
		Node(T data){
			this->data = data;
			this->next = NULL;
		}
		T getData(){
			return data;
		}
		
		Node* getNext(){
			return next;
		}
		
		void setData(T data){
			this->data = data;
		}
		
		void setNext(Node *next){
			this->next = next;
		}

		void print(){
			cout<<data<<"->";
		}
};

template <typename T> 

class LinkList{
	private:
		Node<T> *head;
	public:
		LinkList(){
			head = NULL;
		}

		void insertB(T data){
			Node<T> *newnode = new Node<T>(data);	
			if( head == NULL){
				head = newnode;
			}else{
				newnode->setNext( head );
				head = newnode;
			}
		}
		
		
		void insertE(T data){
			Node<T> *newnode = new Node<T>(data);	
			if( head == NULL){
				head = newnode;
			}else{
				Node<T> *temp = head;
				while( temp->getNext() != NULL ){
					temp = temp->getNext();
				}
				temp->setNext( newnode );
			}
		}
		
		void insertBefore(T before, T data){
			Node<T> *newnode = new Node<T>(data);
			Node<T> *temp = head;
			Node<T> *prev = NULL;

			while( temp != NULL){
				if( temp->getData() == before ){
					break;
				}
				prev = temp;
				temp = temp->getNext();
			
			}
			if( prev == NULL){
				insertB( data );
			}else{
				prev->setNext( newnode );
				newnode->setNext( temp );	
			}
		}
		
		void deleteB(T data){

			Node<T> *temp = head;
			Node<T> *prev = NULL;

			while( temp != NULL){
					
				if(temp->getNext() != NULL ){
					if( temp->getNext()->getData() == data)
						break;
				}	
				prev = temp;
				temp = temp->getNext();
			}
			if( prev != NULL && temp != NULL ){
				prev->setNext( temp->getNext() );
			}	
		}	
		
		void print(){
			Node<T> *temp = head;
			while( temp != NULL ){
				temp->print();
				temp = temp->getNext();
			}
			cout<<"NULL"<<endl;

		}	
};

void list(){
	cout<<"a insert END"<<endl;
	cout<<"b insert Begining"<<endl;
	cout<<"p print"<<endl;
	cout<<"i insert Before (before, data)"<<endl;
	cout<<"d delete Before"<<endl;
	cout<<"e exit"<<endl;
	cout<<"l list"<<endl;
}		

int main(){

	LinkList <int>ll;
	char cmd;	
	while(1){
		cin>>cmd;
		if( cmd == 'e')
			break;
		if( cmd == 'b'){
			int d ;
			cin>>d;
			ll.insertB(d);
		}
		if( cmd == 'l'){
			list();
		}	
		if( cmd == 'd'){
			int d;
			cin>>d;
			ll.deleteB( d );
		}
		if( cmd == 'i'){
			int d,b;
			cin>>b>>d;
			ll.insertBefore(b, d);
		}	
		if( cmd == 'a'){
			int d ;
			cin>>d;
			ll.insertE(d);
		}
		if( cmd == 'p'){
			ll.print();
		}
	}	
}	
