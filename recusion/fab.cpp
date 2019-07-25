#include <iostream>
#include <stdlib.h>
#include <unordered_map> 

using namespace std;

unordered_map<int, int> fabo; 


int fab(int n){

	if( n == 0 || n == 1)
		return 1;
	if( fabo[n] > 0)
		return fabo[n];	
	return ( fabo[n] = fab(n - 1) + fab(n - 2));
}

int main(int argc,char ** args){
	for(int  i = 0; i < atoi(args[1]); i++)
		cout<<fab(i)<<endl;
return 0;
}

