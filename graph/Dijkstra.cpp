#include <iostream>
#include <string>
#include "stack.cpp"
#include "queue.cpp"

using namespace std;

class Graph{

	private: 
		int edges;
		int vertics;
		string* vertex;
		int **matrix;
		int *dis; 
		int *tbc; 
		int *pred; 
	public:
		Graph(int  vertics, int edges){
			this->vertics = vertics;
			this->edges = edges;
			this->vertex = new string[vertics];
			matrix = new int*[ vertics ];
			for(int i = 0; i < vertics; i++){
				matrix[i] = new int[ vertics ];
				vertex[i] = "";
			}

			for(int i = 0; i < vertics; i++)
			for(int j = 0; j < vertics; j++)
				matrix[i][j] = 999999;
		}

		int getIndex(string vertexName){
			for(int i = 0; i < vertics; i++){
				if( vertex[i].compare( vertexName ) == 0 )
					return i;
				else if (vertex[i].compare( "" ) == 0 ){
					vertex[i] = vertexName;
					return i;			
				}		
			}
		return -1;
		}
		
		void addEdges(string t, string f, int weight){
			matrix[ getIndex(t) ][ getIndex(f) ] = weight;
			matrix[ getIndex(f) ][ getIndex(t) ] = weight;
		}
		
		void print(){
			for(int i = 0; i <  vertics; i++){
				cout<<i<<" "<< vertex[i]<<endl;
			}
			cout<<endl;
			for(int i = 0; i <  vertics; i++){
				for(int j = 0; j < vertics; j++){
					cout<<matrix[i][j]<<" ";
				}
				cout<<endl;
			}	
		}
		
		void init(){
			for(int i = 0 ; i < vertics; i++){
				dis[i] = 9999999;
				tbc[i] = 0;
				pred[i] = -1;
			}
		}
		
		int allChecked(){
			for(int i = 0; i < vertics; i++){
				if( tbc[i] == 0)
					return 0;
			}
		return 1;
		}

		int getMinFromNotChecked(){

			int min = -1;
			int node = -1;

			for(int i = 0; i < vertics; i++){
				if( tbc[i] == 0){
					if( min == -1){
						min = dis[i];	
						node = i;
					}else if ( min > dis[i] ){
						min = dis[i];
						node = i;
					}	
				}
			}
		return node;
		}

		void printPath(string to, string f){
			int fo = getIndex( f );
			string path = "";
			while( pred[ fo ] != -1){
				path = vertex[fo] +" -> "+path;
				fo = pred[ fo ]; 
			}
			cout<<to<<" -> "+path<<endl;	
			cout<<dis[ getIndex(f) ]<<endl;	
		}

		void warshall(){

			for(int i = 0; i < vertics; i++)
				for(int j = 0; j < vertics; j++)
					for(int k = 0; k < vertics; k++){
					if( matrix[j][k] > matrix[j][i] + matrix[i][k])
					 matrix[j][k] = matrix[j][i] + matrix[i][k];								
					}
		}
	
		void printDistance(string to, string fo){
			cout<<matrix[ getIndex(to) ][ getIndex(fo) ]<<endl;
		}
			
		void dijkstra(string city){

			dis = new int[ vertics ];
			tbc = new int[ vertics ];
			pred = new int[ vertics ];
			init();
			dis[ getIndex( city ) ] = 0;
			while( ! allChecked() ){
				int v = getMinFromNotChecked();
				tbc[ v ] = 1;
				for(int  u = 0; u < vertics; u++){
					if( dis[u] > dis[v] + matrix[v][u] ){
						dis[u] = dis[v] + matrix[v][u]; 
						pred[u] = v;            	
					}
				}
			}
		}	
};

int main(){
	int v,e;
	cin>>v>>e;
	Graph graph(v,e);

	for(int i = 0; i < e; i++){
		string t,f;
		int w;
		cin>>t>>f>>w;
		graph.addEdges(t, f, w);
	}
	string to;	
	cin>>to;
	graph.dijkstra( to );
	graph.print();
	while( 1 ){
		string from;
		cout<<"Enter from: ";
		cin>>from;
		if( from.compare("exit") == 0 ){
			break;
		}else{
			graph.printPath(to, from);
		}
	}				
	graph.warshall();
	while( 1 ){
		string to, from;
		cout<<"Enter from to & from : ";
		cin>>to>>from;
		if( from.compare("exit") == 0 ){
			break;
		}else{
			graph.printDistance(to, from);
		}
	}
	

	

return 0;
}
