/*
 *Give a binary tree and a node print all nodes at distance k from that node
 *Time O(n) & space O(1)
 *
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
		Node<T>*next;	//To connect next node in same level
		int indepsum;
		T data;
};
template <class T> Node<T> :: Node(){
	this->leftChild=this->rightChild=NULL;
	this->next=NULL;
	this->indepsum=-1;
}
template <class T> class Tree{
	public:
		Tree();
		Node<T>* makeTree(int,int&,int,int);
		void printAtK(Node<T>*,int,int);
		bool printNodes(Node<T>*,T,int,int&);
		Node<T> *root;
		T *pre;
		T *in;

};
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
}
/* prints nodes at distance K in a subtree */
template <class T> void Tree<T> :: printAtK(Node<T> *current,int i,int k){
	if(!current || i>k)
		return;
	if(i==k){
		OUT(current->data);
		OUT(" ");
		return;
	}
	printAtK(current->leftChild,i+1,k);
	printAtK(current->rightChild,i+1,k);
}
/* prints nodes at distance K from a given node */
template <class T> bool Tree<T>:: printNodes(Node<T>* current,T a,int k,int &i){
	if(!current)
		return 0;
	if(current->data==a){
		printAtK(current->leftChild,0,k-1);
		printAtK(current->rightChild,0,k-1);
		i=0;
		return 1;
	}
	if(printNodes(current->leftChild,a,k,i)){
		i++;
		printAtK(current->rightChild,0,k-i-1);
		if(k==i)
			OUT(current->data<<" ");
		return 1;
	}else if(printNodes(current->rightChild,a,k,i)){
		i++;
		printAtK(current->leftChild,0,k-i-1);
		if(k==i)
			OUT(current->data<<" ");
		return 1;
	}else return 0;
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
	int a,b;
	while(1){
		i=0;
		IN(a);
		IN(b);
		tree.printNodes(tree.root,a,b,i);
		OUT(endl);
	}
}
