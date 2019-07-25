#include "cqueue.cpp"


int main(){

	CQueue<int> queue(10);
	
	while(1){
		int n;
		char *cmd = new char[2];
		cin>>cmd;
		if( cmd[0] == 'b' )
			break;
		else if(cmd[0] == 'e'  ){
			cin>>n;
			queue.enqueue(n);
		}else if( cmd[0] == 'd'  ){
			cout<<queue.dequeue()<<endl;
		}
	}
	
	while( ! queue.isEmpty() ){
		cout<<queue.dequeue()<<endl;
	}
}
