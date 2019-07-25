#include <iostream>

#ifndef __STACK__
#define __STACK__

using namespace std;

template <typename T> 

class Stack{

	private:	
		int size;
		T *stack;
		int top;

		bool isFull(){
			if( top == size)
				return 1;
			else 
				return 0; 
		}
		
	public:
		Stack(){
		}

		Stack(int size){
			this->size = size;
			this->stack = new T[size];
			this->top = 0;
			
		}			

		bool isEmpty(){
			if(top == 0)
				return 1;
			else
				return 0;
		}

		void push(T ch){
			if( isFull() ){
				cout<<"Stack is Full"<<endl;
				return;
			}
			stack[top] = ch;
			top++;
		}
	
		T pop(){
			if( isEmpty() ){
				T tmp;
				cout<<"Stack is empty"<<endl;
				return tmp;
			}	
			top--;
			return stack[top];
		}
};

#endif

