#include <iostream>
#include "linklist.cpp" 

#ifndef __STACK__
#define __STACK__

using namespace std;

template <typename T> 

class Stack{

	private:	
		LinkList<T> ll;
	public:
		Stack(){
				
		}

		bool isFull(){
			Node<T> *newnode = new Node<T>();
			if ( newnode == NULL)	
				return 1;
			else 
				return 0; 
		}

		bool isEmpty(){
			if( ll.getHead() == NULL)
				return 1;
			else
				return 0;
		}

		void push(T ch){
			if( isFull() ){
				cout<<"Stack is Full"<<endl;
				return;
			}
			ll.insertB( ch );
		}
	
		T pop(){
			if( isEmpty() ){
				T tmp;
				cout<<"Stack is empty"<<endl;
				return tmp;
			}	
			return ll.deleteBe();
		}
};

#endif

