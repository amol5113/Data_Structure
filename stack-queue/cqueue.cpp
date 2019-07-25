#include <iostream>

using namespace std;

#ifndef __QUEUE__
#define __QUEUE__

using namespace std;

template <typename T> 

class CQueue{

	private:	
		int size;
		int noe;
		int firstE;
		int lastE;
		T *store;
	public:
		CQueue(){}
		
		CQueue(int size){
			this->firstE = 0;
			this->lastE = 0;
			this->size = size;
			this->store = new T[size]; 
			this->noe = 0;
		}
		
		bool isFull(){
			if( noe == size)
				return 1;
			return 0;
		}
		
		bool isEmpty(){
			if( noe == 0)
				return 1;
			return 0;	
		}
		
		void enqueue(T data){
			if( isFull() ){
				cout<<"Queue is full"<<endl;
				return ;
			}
			store[ this->lastE ] = data;
			noe++;
			lastE = ( lastE + 1 ) % size;		
		}

		T dequeue(){
			if( isEmpty() ){
				T tmp;
				cout<<"Queue is Empty"<<endl;
				return tmp;
			}
			T data = store[ firstE ];
			firstE = (firstE + 1) % size;
			noe--;
			return data;
		}
};

#endif

