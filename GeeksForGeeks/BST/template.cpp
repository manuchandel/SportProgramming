/*
 *Template for Binary search Tree.
 *Also includes a function which can create BST from preorder and inorder traversals
*/
#include <iostream>
#include <cstdlib>
#include <queue>
#include <list>
#define IN(a) cin>>a
#define OUT(a) cout<<a
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
class Node{
	public:
		Node();
		Node *leftChild,*rightChild;
		int data;
};
Node :: Node(){
	this->leftChild=this->rightChild=NULL;
}
class Tree{
	public:
		Tree();
		Node *makeTree(int,int&,int,int);
		Node *root;
		int *pre;
		int *in;

};
Tree:: Tree(){
	this->root=NULL;
}
Node* Tree::makeTree(int n,int &i,int l,int r)
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
	Node *node=new Node();
	node->data=this->pre[i];
	int j=l;
	while(in[j]!=this->pre[i]) j++;
	i++;
	node->leftChild=makeTree(n,i,l,j-1);
	i++;
	node->rightChild=makeTree(n,i,j+1,r);
	return node;
}
void takeinput(Tree &tree){
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
