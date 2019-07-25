#include <iostream> 
#include <unordered_map> 
using namespace std; 
  
int main() 
{ 
    unordered_map<string, int> umap; 
  
    umap["Geeks"] = 10; 
    umap["Hacker"] = 20; 
    umap["Coder"] = 30; 
    umap["Programer"] = 5; 

    string input;
    cin>>input;   	
    cout<<umap[input]<<endl;         	       	

      		
    for (auto x : umap) 
      cout << x.first << " " << x.second << endl; 
return 0;
} 
