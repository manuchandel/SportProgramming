/*
 *print root to leaf path
 *Time O(n)
 *Avg space O(logn) & worst space O(n)
*/
#include <iostream>
#include <cstdlib>
#include <queue>
#define IN(a) cin>>a
#define OUT(a) cout<<a
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
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
		Node<T>* makeTree(int,int&,int,int);
		int height(Node<T>*);
		void rootToLeaf(Node<T>*,T*,int);
		Node<T>*root;
		T *pre;
		T *in;

};
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
}
template <class T> int Tree<T> :: height(Node <T>* current){
	if(!current)
		return 0;
	return 1+max(height(current->leftChild),height(current->rightChild));
}
/* utility function to print array*/
template <class T> void printArray(T *arr,int n){
	int i;
	FOR(i,n+1)
		OUT(arr[i]<<"->");
	OUT(arr[n]);OUT(endl);
}
/* prints root to leaf paths */
template <class T> void Tree<T>:: rootToLeaf(Node<T> *current,T *arr,int i){
	if(!current)
		return;
	arr[i]=current->data;
	if(!current->leftChild && !current->rightChild){
		printArray(arr,i);
		return;
	}
	rootToLeaf(current->leftChild,arr,i+1);
	rootToLeaf(current->rightChild,arr,i+1);
}
/* constructs tree from given two traversals, two traversals should be unique i.e tree shouldnt have duplicate elements*/
template <class T> Node<T>* Tree<T>::makeTree(int n,int &i,int l,int r)
{
	if(l>r){
		i--;
		return NULL;
	}
	if(i>=n){
		OUT("There is error in the traversals");
		OUT(endl);
		exit(0);

	}
	Node<T> *node=new Node<T>();
	node->data=this->pre[i];
	int j=l;
	while(in[j]!=this->pre[i]) j++;
	i++;
	node->leftChild=makeTree(n,i,l,j-1);
	i++;
	node->rightChild=makeTree(n,i,j+1,r);
	return node;

}
int main(){
	int i;
	int n; //no of elements in traversal
	IN(n);	//input no of elements
	Tree <int> tree;
	tree.pre=new int[n];
	tree.in=new int[n];
	FOR(i,n)
		IN(tree.pre[i]);	//input preorder traversal
	FOR(i,n)
		IN(tree.in[i]);	//input inorder traversal
	i=0;
	tree.root=tree.makeTree(n,i,0,n-1);	//create tree according to traversals
	int *arr=new int[tree.height(tree.root)];
	tree.rootToLeaf(tree.root,arr,0);	//print root to leaf paths
}
