/*
 *Construct Full binary Tree from post order and pre order traversals
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
		void inTraversal(Node<T>*);
		Node<T>*root;
		T *pre;
		T *post;

};
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
}
template <class T> void Tree<T> :: inTraversal(Node <T>* current){
	if(!current)
		return;
	inTraversal(current->leftChild);
	OUT(current->data); OUT(" ");
	inTraversal(current->rightChild);
}
/* constructs full tree from given two pre and post traversals,traversals should be unique i.e tree shouldnt have duplicate elements*/
template <class T> Node<T>* Tree<T>::makeTree(int n,int &i,int l,int r)
{
	if(l>r){
		i--;
		return NULL;
	}
	if(i>=n){
		OUT("Traversals are incorrect");OUT(endl);
		exit(0);
	}
	Node<T> *node=new Node<T>();
	node->data=pre[i];
	if(i==n-1)
		return node;
	int j=r;
	while(j>=l && post[j]!=pre[i+1]) j--;
	i++;
	node->leftChild=this->makeTree(n,i,l,j);
	i++;
	node->rightChild=this->makeTree(n,i,j+1,r-1);
	return node;

}
int main(){
	int i;
	int n; //no of elements in traversal
	IN(n);	//input number
	Tree <int> tree;
	tree.pre=new int[n];
	tree.post=new int[n];
	FOR(i,n)
		IN(tree.pre[i]);	//input preorder traversal
	FOR(i,n)
		IN(tree.post[i]);	//input inorder traversal
	i=0;
	tree.root=tree.makeTree(n,i,0,n-1);	//create full tree according to traversals
	tree.inTraversal(tree.root);	//print in order traversal
	OUT(endl);
}
