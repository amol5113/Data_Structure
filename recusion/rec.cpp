#include <iostream>

using namespace std;

int rec(int n){
	cout<<n<<endl;
	if( n < 0)
		return n;
	rec( n - 1  );
	cout<<n<<endl;
}

int main(){
	rec(5);
	cout<<"Hello"<<endl;
return 0;
}

