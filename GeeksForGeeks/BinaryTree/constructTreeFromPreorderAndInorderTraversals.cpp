/*
 *Construct Tree from pre order and inorder traversals
 *Time O(n^2)
*/
#include <iostream>
#include <cstdlib>
#include <queue>
#define IN(a) cin>>a
#define OUT(a) cout<<a
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
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
		Node<T>* makeTree(int,int&,int,int);
		void postOrderTraversal(Node<T>*);
		Node<T>*root;
		T *pre;
		T *in;

};
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
}
template <class T> void Tree<T> :: postOrderTraversal(Node <T>* current){
	if(!current)
		return;
	postOrderTraversal(current->leftChild);
	postOrderTraversal(current->rightChild);
	OUT(current->data); OUT(" ");
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
	if(!this->root)
		root=node;
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
	tree.makeTree(n,i,0,n-1);	//create tree according to traversals
	tree.postOrderTraversal(tree.root);	//print postorder traversals
	OUT(endl);
}
