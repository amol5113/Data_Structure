#include <iostream>
#include <string.h>
#include "stack.cpp"
#include "queue.cpp"

using namespace std;

class Node{

	private:
		int data;
		Node *left;
		Node *right;
	public:
		Node(){}

		Node(int data){
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}

		~Node(){
			delete left;
			delete right;
		}

		void setData(int data){
			this->data = data;
		}

		int getData(){
			return this->data;
		}

		void setLeft(Node* left){
			this->left = left;
		}

		void setRight(Node* right){
			this->right = right;
		}

		Node* getLeft(){
			return left;
		}

		Node* getRight(){
			return right;
		}

		void print(){
			cout<<data<<"->";
		}

};

class BST{

	private:
		Node *root;
	public:
		BST(){
			root = NULL;
		}

		~BST(){
	
		}
		
		void insert(int data){

			Node *newnode = new Node(data);

			if( root == NULL){
				root = newnode;
			}else{
				Node *temp = root;
				Node *prev = NULL;
				while( temp != NULL ){
					prev = temp;
					if( data > temp->getData() ){
						temp = temp->getRight();
					}else{
						temp = temp->getLeft();
					}
				}
				if( data > prev->getData() ){
					prev->setRight( newnode );
				}else{
					prev->setLeft( newnode );
				}
			}
		}

		void traversalB(){

			Queue<Node*> store(100);
			store.enqueue( root );
					
			while( ! store.isEmpty() ){
				Node *node = store.dequeue();
				node->print();
				if( node->getRight() != NULL){
					store.enqueue( node->getRight() );
				}
				if( node->getLeft() != NULL){
					store.enqueue( node->getLeft() );
				}
			}
			cout<<endl;	
		}

		void traversalD(){

			Stack<Node*> store(100);
			store.push( root );
					
			while( ! store.isEmpty() ){
				Node *node = store.pop();
				node->print();
				if( node->getRight() != NULL){
					store.push( node->getRight() );
				}
				if( node->getLeft() != NULL){
					store.push( node->getLeft() );
				}
			}
			cout<<endl;	
		}
		
		void inorder(Node *root){
			if( root != NULL){
				inorder( root->getLeft() );
				root->print();
				inorder( root->getRight() );

			}	
		}
			
		void inorder(){
			inorder( root );
			cout<<endl;
		}
		
		Node *find(Node *root, int data){
			Node *temp = root;
			while( temp != NULL && temp->getData() != data ){
				if( data > temp->getData() )
					temp = temp->getRight();
				else
					temp = temp->getLeft();
			}
		return temp;
		}

		Node *findParent(Node *root, int data){
			Node *parent = NULL;
			Node *temp = root;
			while( temp != NULL && temp->getData() != data ){
				parent = temp;
				if( data > temp->getData() )
					temp = temp->getRight();
				else
					temp = temp->getLeft();
			}
		return parent;
		}

		void deleteNode(int data){

			Node *node = find( root, data );

			if( node != NULL ){

				if( node->getLeft() == NULL && node->getRight() == NULL)
					root = deleteNoChild(root, node );
				else if( node->getLeft() != NULL && node->getRight() == NULL )
					root = deleteOneChild(root, node );
				else if( node->getLeft() == NULL && node->getRight() != NULL )
					root = deleteOneChild(root, node );
				else
					root = deleteTwoChild(root, node );
			}else{
				cout<<"Data not Found!"<<endl;
			}
		}

		Node* deleteNoChild(Node *root, Node *node){

			if( root == node ){
			    root = NULL;	
			}else{
			        Node* parent = findParent( root, node->getData() );	

				if( node->getData() > parent->getData() ){
					parent->setRight( NULL );
				}else{	
					parent->setLeft( NULL );
				}
				node = NULL;
			}
		return root;
		}
		
		Node* deleteOneChild(Node* root, Node *node){

			Node* subchild = NULL;

			if( node->getLeft() != NULL )
				subchild = node->getLeft();
			else
				subchild = node->getRight();
			
			if( root == node){
				root = NULL;
				root = subchild;
			}else{
			        Node* parent = findParent( root, node->getData() );	
				if( node->getData() > parent->getData() )
					parent->setRight( subchild );
				else
					parent->setLeft( subchild );
			}
		return root;
		}

		Node* getLeftKaRightMost(Node* root){
			while( root->getRight() != NULL )
				root = root->getRight();
		return root;
		}

		Node* deleteTwoChild(Node *root, Node *node){

			Node* rightMost = getLeftKaRightMost( node->getLeft() );
			int data = node->getData();
			node->setData( rightMost->getData() );
			rightMost->setData( data );

			if( rightMost->getLeft() != NULL || rightMost->getRight() != NULL ){

				node->setLeft (  deleteOneChild( node->getLeft(), rightMost ) );
			}else{
				node->setLeft (  deleteNoChild( node->getLeft(), rightMost ) );
			}
		return root;	
		}

		int max(int left, int right){
			return	left > right ? left : right;
		}
	
		int height(Node *root){
			if(root == NULL)
				return 0;
			return max(height(root->getLeft())+1,height(root->getRight()) + 1);
		}
		
		
		int height(){
			return height( root );
		}

};	

int main(){
	BST bst;
	while(1){
		char cmd[3];
		cin>>cmd;
		if( strcmp(cmd, "in") == 0 ){
			int n;
			cin>>n;
			bst.insert(n);
		}

		if( strcmp(cmd, "io") == 0  ){
			bst.inorder();
		}
		if( strcmp(cmd, "h") == 0  ){
			cout<<bst.height()<<endl;
		}

		if( strcmp(cmd, "ex") == 0 ){
			break;
		}
		if( strcmp(cmd, "df") == 0 ){
			bst.traversalD();
		}
		if( strcmp(cmd, "bf") == 0 ){
			bst.traversalB();
		}
		if( strcmp(cmd, "dl") == 0 ){
			int n;
			cin>>n;
			bst.deleteNode( n );
		}	
	}	
return 0;
}
