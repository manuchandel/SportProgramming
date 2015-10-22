/*
 *Write a function to detect if two trees are isomorphic.
 *Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e.
 *by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped. 
 *Two empty trees are isomorphi
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
/* finds isIsomorphic relationship */
template <class T> bool isIsomorphic(Node<T> *n1,Node<T> *n2){
	if(!n1 && !n2)
		return true;
	else if(!n1 || !n2)
		return false;
	else if(n1->data != n2->data)
		return false;
	// There are two possible cases for n1 and n2 to be isomorphic
  // Case 1: The subtrees rooted at these nodes have NOT been "Flipped".
  // Case 2: The subtrees rooted at these nodes have been "Flipped"
	bool one=isIsomorphic(n1->leftChild,n2->leftChild)&& isIsomorphic(n1->rightChild,n2->rightChild);
	if(one) return true;
	bool other=isIsomorphic(n1->leftChild,n2->rightChild) && isIsomorphic(n1->rightChild,n2->leftChild);
	return other;

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
	Tree<int> tree1;
	Tree<int> tree2;
	OUT("Input for first Tree\n");
	takeinput(tree1);
	OUT("Input for Second Tree\n");
	takeinput(tree2);
	if(isIsomorphic(tree1.root,tree2.root))
		OUT("Trees are Isomorphic\n");
	else OUT("Trees are not Isomorphic\n");
}
