#include <iostream>

using namespace std;

#ifndef __QUEUE__
#define __QUEUE__

using namespace std;

template <typename T> 

class Queue{

	private:	
		int size;
		int firstE;
		int lastE;
		T *store;
	public:
		Queue(){}
		
		Queue(int size){
			this->firstE = 0;
			this->lastE = 0;
			this->size = size;
			this->store = new T[size]; 
		}
		
		bool isFull(){
			if( lastE >= size)
				return 1;
			return 0;
		}
		
		bool isEmpty(){
			if(firstE == lastE)
				return 1;
			return 0;	
		}
		
		void enqueue(T data){
			if( isFull() ){
				cout<<"Queue is full"<<endl;
				return ;
			}
			store[ this->lastE ] = data;
			this->lastE++;		
		}

		T dequeue(){
			if( isEmpty() ){
				T tmp;
				cout<<"Queue is Empty"<<endl;
				return tmp;
			}
			T data = store[ firstE ];
			firstE++;
			if( firstE == lastE){
				firstE = lastE = 0;
			}
			return data;
		}
};

#endif

