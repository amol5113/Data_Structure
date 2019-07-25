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
			//matrix[ getIndex(f) ][ getIndex(t) ] = weight;
		}
		
		int isEdges(string t, string f){
			return matrix[ getIndex(t) ][ getIndex(f) ];
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

		int allVisited(int *visited){
			for(int i = 0; i < vertics; i++)
				if( visited[i] == 0)
					return 0;
		return 1;
		}

		int getNotVisted(int *visited){
			for(int i = 0; i < vertics; i++)
				if( visited[i] == 0)
					return i;
		return -1;
		}	

		void traversalBFS(){

			int *visited = new int[ vertics ];

			for(int i = 0; i < vertics; i++)
				visited[i] = 0;

			while( ! allVisited( visited ) ){

				Queue<int> store( vertics );
				int notVisted = getNotVisted( visited );
				store.enqueue( notVisted );

				while( !store.isEmpty() ){
					int v = store.dequeue();
					visited[v] = 1;
					cout<< vertex[v] << " ";
					for(int i = 0; i < vertics; i++){
						if( v != i && matrix[v][i] > 0){
							if( visited[i] == 0)
								store.enqueue( i );
						}
					}
				}	
			}
			cout<<endl;	
		}

		void traversalDFS(){

			int *visited = new int[ vertics ];
			for(int i = 0; i < vertics; i++)
				visited[i] = 0;

			while( !allVisited( visited ) ){
				Stack<int> store( vertics );
				int notVisted = getNotVisted( visited );
				store.push( notVisted );

				while( !store.isEmpty() ){
					int v = store.pop();
					visited[v] = 1;
					cout<< vertex[v] << " ";
					for(int i = 0; i < vertics; i++){
						if( v != i && matrix[v][i] > 0){
							if( visited[i] == 0)
								store.push( i );
						}
					}
				}
			}
			cout<<endl;	
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
	graph.print();	

	graph.traversalDFS();
	graph.traversalBFS();

	/*
	while(1){
		string t,f;
		cin>>t>>f;
		if( graph.getIndex(t) == -1 || graph.getIndex(f) == -1)
			break;
		int dis = graph.isEdges(t,f);

		if( dis > 0 ){
			cout<<"Yes "<<dis<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}*/	
return 0;
}
