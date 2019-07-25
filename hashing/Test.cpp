#include <iostream>
#include <stdlib.h>
using namespace std;

int test(int n){
	for(int i = n; i >= 0; i--){
		cout<<"("<<n<<"/"<<i<<")"<<n/i<<endl;
	}
return 0;
}


int main(int argc, char** argv){
	int n;	
	cin>>n;
	cout<< test(n)<<endl;	
return 0;
}
