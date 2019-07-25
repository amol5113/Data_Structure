#include "stack.cpp"

int main(){

	Stack<int> st(10);

	while(1){
		int n;
		cin >> n;
		if( n == -1 )
			break;
		st.push(n);
	}
	
	while( !st.isEmpty() ){
		cout<<st.pop()<<endl;
	}
	
return 0;
}
