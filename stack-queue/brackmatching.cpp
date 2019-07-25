#include <iostream>
#include "stack.cpp"

int main(int argc, char** argv){
	
	Stack<char> stack(20);
	string exp( argv[1] );

	bool invalid =0;
	for( int i = 0; i < exp.size(); i++){
		if( exp.at(i) == '(' || exp.at(i) == '{' || exp.at(i) == '[' ){
			stack.push(  exp.at(i) ) ;
		}else{
			if( stack.isEmpty() ){
				cout<<"Invalid: Less opening bracket"<<endl;
				invalid = 1;
				break;
			}

			char opt = stack.pop();

			if( ( opt == '[' && exp.at(i) != ']' ) ||
			    ( opt == '(' && exp.at(i) != ')' ) || 
			    ( opt == '{' && exp.at(i) != '}' )       		           	
			){
				cout<<"Invalid: bracket mismatch"<<endl;
				invalid = 1;
				break;
			}

		}
	}			
	if( stack.isEmpty() ){
		if( !invalid ){
			cout<<"Expression "<<exp<<" is valid"<<endl;
		}
	}else{
		cout<<"Invalid: more number of opening barcket"<<endl;
	}
return 0;
}


