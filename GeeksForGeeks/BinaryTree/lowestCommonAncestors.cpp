/*
 *Given a Binary Tree, Given two keys find Lowest Common Ancestors.
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
		Node<T>* lowestCommonAncestor(Node<T>*,T,T);
		Node<T> *root;
		T *pre;
		T *in;

};
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
}
/* Returns pointer to lowest common ancestors for two nodes in binary tree */
template <class T> Node<T>* Tree<T>:: lowestCommonAncestor(Node<T>* current,T a,T b){
	if(!current)
		return NULL;
	if(current->data==a || current->data==b)
		return current;
	Node<T> *left=lowestCommonAncestor(current->leftChild,a,b);
	Node<T> *right=lowestCommonAncestor(current->rightChild,a,b);
	if(left && right)
		return current;
	else if(left)
		return left;
	else return right;
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
		IN(a);
		IN(b);
		OUT(tree.lowestCommonAncestor(tree.root,a,b)->data);
		OUT(endl);
	}
}
