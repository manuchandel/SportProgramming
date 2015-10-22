/*
 *Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL).
 *The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL.
 *The order of nodes in DLL must be same as Inorder of the given Binary Tree.
 *The first node of Inorder traversal (left most node in BT) must be head node of the DLL.
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
		Node<T> *root;
		T *pre;
		T *in;

};
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
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
/* converts tree to doubly link list in inorder fashion*/
template <class T> void treeToDll(Node<T> *current,Node<T> **previous){
	if(!current)
		return;
	treeToDll(current->leftChild,previous);
	if((*previous))
		(*previous)->rightChild=current;
	current->leftChild=(*previous);
	(*previous)=current;
	treeToDll(current->rightChild,previous);
}
/* Aux function uses dll converter */
template <class T> void treeToDllAux(Tree<T> &tree){
	Node<T> *current=NULL;
	treeToDll(tree.root,&current);
	current=tree.root;
	while(current->leftChild)
		current=current->leftChild;
	/* points root to the first node in inorder successor */
	tree.root=current;
	while(current->rightChild){
		OUT(current->data<<" ");
		current=current->rightChild;
	}
	OUT(current->data<<endl);
	/* prints dll while traversing left */
	while(current){
		OUT(current->data<<" ");
		current=current->leftChild;
	}
	OUT(endl);
}
void takeinput(Tree<int> &tree){
	int n,i;
	IN(n);
	tree.pre=new int[n];
	tree.in=new int[n];
	FOR(i,n)
		IN(tree.pre[i]);	//input preorder traversal
	FOR(i,n)
		IN(tree.in[i]);	//input inorder traversal
	i=0;
	tree.root=tree.makeTree(n,i,0,n-1);	//create tree according to traversals
}
int main(){
	Tree<int> tree;
	takeinput(tree);
	treeToDllAux(tree);
}
