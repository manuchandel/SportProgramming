/*
 *Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.
 *The maximum sum path may or may not go through root.
 *Given a Binary Tree (BT), Print distance between two nodes
 *Time O(n) & space O(1)
 *
 */
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <limits.h>
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
/*
 *returns pointer to the common ancestor
 *B[0] keeps the value of maxSum from node to the leaf
 *B[1] keeps the value of the maxSum from leaf to leaf untill the given node
 */
vector<int> maxSum(Node<int> *current){
	vector<int> B(2,INT_MIN);
	if(!current)
		return B;
	if(!current->leftChild && !current->rightChild){
		B[0]=B[1]=current->data;
		return B;
	}
	vector<int> left;
	vector<int> right;
	left=maxSum(current->leftChild);
	right=maxSum(current->rightChild);
	if(current->leftChild && current->rightChild){
		B[0]=current->data+max(left[0],right[0]);
		B[1]=max(max(left[1],right[1]),left[0]+right[0]+current->data);
	}else if(current->leftChild){
		B[0]=current->data+left[0];
		B[1]=left[1];
	}else if(current->rightChild){
		B[0]=current->data+right[0];
		B[1]=right[1];
	}
	//OUT(B[0]<<" "<<B[1]<<endl);
	return B;

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
	vector<int> A=maxSum(tree.root);
	OUT(max(A[0],A[1]));
	OUT(endl);
}
