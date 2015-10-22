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
int max(int a,int b){
	if(b>a)
		return b;
	return a;
}
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
		int size(Node<T>*);
		int depth(Node<T>*);
		int leafNodes(Node <T>*);
		void deleteTree(Node<T>*);
		void deleteSubTree(Node<T>*current, Node<T>**previous);
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
/* returns number of nodes in a tree */
template<class T> int Tree<T>::size(Node<T>*current){
	if(!current)
		return 0;
	return 1+this->size(current->leftChild)+this->size(current->rightChild);
}
/* returns depth of tree starting at level one  */
template<class T> int Tree<T>::depth(Node<T>*current){
	if(!current)
		return 0;
	return 1+max(this->depth(current->leftChild),this->depth(current->rightChild));
}
/* returns no of leafnodes of subtree rooted at current */
template<class T> int Tree<T>::leafNodes(Node<T>*current){
	if(!current)
		return 0;
	if(!current->leftChild && !current->rightChild)
		return 1;
	return this->leafNodes(current->leftChild)+this->leafNodes(current->rightChild);
}
/* deletes the tree rooted at current */
template<class T> void Tree<T>::deleteTree(Node<T>*current){
	if(!current)
		return;
	deleteTree(current->leftChild);
	deleteTree(current->rightChild);
	delete current;
}
/* deletes the tree pointed with current and points previous to NULL*/
template<class T> void Tree<T>::deleteSubTree(Node<T>*current, Node<T>**previous){
	deleteTree(current);
	*previous=NULL;
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
	printf("%d",tree.leafNodes(tree.root->leftChild));
	cout<<endl;
	tree.deleteSubTree(tree.root->leftChild,&(tree.root->leftChild));
	tree.postorderTraversal(tree.root);
	cout<<endl;
	printf("%d\n",tree.leafNodes(tree.root));
}
