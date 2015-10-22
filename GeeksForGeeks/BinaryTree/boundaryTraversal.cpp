/*
 *Do a boundary traversal of binary tree in anti clockwise fashion from root
 *Time O(n) & space O(1)
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
		Node<T>* makeTree(string,string,int&,int,int);
		bool isLeaf(Node<T>*);
		void printLeftNodes(Node<T>*);
		void printLeafNodes(Node<T>*);
		void printRightNodes(Node<T>*);
		void boundaryTraversal();
		Node<T>*root;

};
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
}
/* utility function to check whether given node is leaf or not */
template <class T> bool Tree<T>:: isLeaf(Node<T>* current){
	if(current->leftChild || current->rightChild)
		return false;
	return true;
}

/*prints all the left nodes in anti-clockwise manner in a subtree rooted at current except the leaf nodes*/
template <class T> void Tree<T>:: printLeftNodes(Node<T> *current){
	if(!current || this->isLeaf(current))
		return;
	OUT(current->data); OUT(" ");
	if(!current->leftChild)
		printLeftNodes(current->rightChild);
	else printLeftNodes(current->leftChild);
}
/*prints all the Leaf nodes in anti-clockwise manner in a subtree rooted at current*/
template <class T> void Tree<T>:: printLeafNodes(Node<T> *current){
	if(!current)
		return;
	if(this->isLeaf(current)){
		OUT(current->data); OUT(" ");
		return;
	}
	printLeafNodes(current->leftChild);
	printLeafNodes(current->rightChild);
}
/*prints all the right nodes in anti-clockwise manner in a subtree rooted at current except the leaf nodes*/
template <class T> void Tree<T>:: printRightNodes(Node<T> *current){
	if(!current || this->isLeaf(current))
		return;
	if(!current->rightChild)
		printRightNodes(current->leftChild);
	else printRightNodes(current->rightChild);
	OUT(current->data); OUT(" ");
}
/* prints all the nodes at boundary of a tree in anticlockwise manner from the root */
template <class T> void Tree<T>:: boundaryTraversal(){
	if(!this->root)	//if tree is empty return
		return;
	OUT(this->root->data); OUT(" ");	//print root
	this->printLeftNodes(this->root->leftChild);	//print left boundary
	this->printLeafNodes(this->root->leftChild);	//print leafnodes in leaft subtree
	this->printLeafNodes(this->root->rightChild);	//print leafnodes in right subtree
	this->printRightNodes(this->root->rightChild);	//print right boundary
	OUT(endl);
}
/* constructs tree from given two traversals two traversals should be unique i.e tree shouldnt have duplicate elements*/
template <class T> Node<T>* Tree<T>::makeTree(string pre,string in,int &i,int l,int r)
{
	if(l>r){
		i--;
		return NULL;
	}
	if(i>=pre.length()){
		OUT("There is error in the traversals");
		OUT(endl);
		exit(0);

	}
	Node<T> *node=new Node<T>();
	if(!this->root)
		root=node;
	node->data=pre[i];
	int j=l;
	while(in[j]!=pre[i]) j++;
	i++;
	node->leftChild=makeTree(pre,in,i,l,j-1);
	i++;
	node->rightChild=makeTree(pre,in,i,j+1,r);
	return node;

}
int main(){
	int i;
	string preorderBuffer;
	string inorderBuffer;
	Tree <char> tree;
	IN(preorderBuffer);	//input preorder traversal
	IN(inorderBuffer);	//input inorder traversal
	i=0;
	tree.makeTree(preorderBuffer,inorderBuffer,i,0,preorderBuffer.length()-1);	//create tree according to traversals
	tree.boundaryTraversal();	//print all boundary nodes in anticlockwise fashion
}
