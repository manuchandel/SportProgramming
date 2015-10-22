/*
 *Basic Tree operations
 *All funtions take O(n) time
 */
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(int a=0;a<b;a++)
#define LOOP(a,b,c) for(int a=b;a<c;a++)
using namespace std;
template <class T> class Node{
	public:
		Node();
		Node<T> *leftChild,*rightChild;
		T data;	
};
template <class T> Node<T> :: Node(){
	this->leftChild=this->rightChild=NULL;
}
template <class T> class Tree{
	public:
		Tree();
		Node<T>* makeCompleteTree(T*,int,int);	
		void postorderTraversal(Node<T>*);
		void preorderTraversal(Node<T>*);
		void inorderTraversal(Node<T>*);
		void levelorderTraversal(Node<T>*,int);
		unordered_map <int,vector<T>> mymap;
		Node<T>*root;

};
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
}
template <class T> Node<T>* Tree<T>:: makeCompleteTree(T* array,int i,int n){
	if(i>=n)
		return NULL;
	Node<T> *node=new Node<T>();
	if(!this->root)
		root=node;
	node->data=array[i];
	node->leftChild=this->makeCompleteTree(array,2*i+1,n);
	node->rightChild=this->makeCompleteTree(array,2*i+2,n);
	return node;
};
template <class T> void Tree<T>:: postorderTraversal(Node<T>*current){
	if(!current)
		return;
	this->postorderTraversal(current->leftChild);
	this->postorderTraversal(current->rightChild);
	cout<<current->data<<endl;	
}
template <class T> void Tree<T>:: preorderTraversal(Node<T>*current){
	if(!current)
		return;
	cout<<current->data<<endl;
	this->postorderTraversal(current->leftChild);
	this->postorderTraversal(current->rightChild);	
}
template <class T> void Tree<T>:: inorderTraversal(Node<T>*current){
	if(!current)
		return;
	this->postorderTraversal(current->leftChild);
	cout<<current->data<<endl;
	this->postorderTraversal(current->rightChild);
		
}
template <class T> void Tree<T>:: levelorderTraversal(Node<T>*current,int h){
	if(!current)
		return;
	this->mymap[h].push_back(current->data);
	this->levelorderTraversal(current->leftChild,h+1);
	this->levelorderTraversal(current->rightChild,h+1);
	if(h==0){
		FOR(i,mymap.size())
			FOR(j,mymap[i].size())
				cout<<this->mymap[i][j]<<" ";
			cout<<endl;
	}
}
int main(){
	int n;
	IN(n);
	int *array=new int[n];
	FOR(i,n)
		array[i]=i;
	Tree <int> tree;
	tree.makeCompleteTree(array,0,n);
	tree.postorderTraversal(tree.root);
	tree.levelorderTraversal(tree.root,0);
}
