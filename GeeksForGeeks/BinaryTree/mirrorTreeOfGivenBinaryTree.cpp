/*
 *Basic Tree operations creating mirror of tree
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
		void mirrorTree(Node<T>*);
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
	cout<<current->data<<" ";	
}
/* utility function swaps pointers */
template <class T> void swap(Node<T>**a,Node<T>**b){
	Node<T> *temp=*a;
	*a=*b;
	*b=temp;
}
/* function creating mirror tree of given subtree rooted at current pointer*/
template <class T> void Tree<T>:: mirrorTree(Node<T> *current){
	if(!current)
		return;
	mirrorTree(current->leftChild);
	mirrorTree(current->rightChild);
	swap(&(current->leftChild),&(current->rightChild));
}
int main(){
	int n;
	IN(n);
	int *array=new int[n];
	FOR(i,n)
		array[i]=i;
	Tree <int> tree;
	/* sample operations */
	tree.makeCompleteTree(array,0,n);
	tree.postorderTraversal(tree.root);
	cout<<endl;
	tree.mirrorTree(tree.root->leftChild);
	tree.postorderTraversal(tree.root);
	cout<<endl;
}
