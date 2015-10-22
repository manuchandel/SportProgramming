/*
 *Check whether given tree is complete binary tree or not
 *A node is ‘Full Node’ if both left and right children are not empty (or not NULL).
 *once a node is found which is NOT a Full Node, all the following nodes must be leaf nodes.
 *If a node has empty left child, then the right child must be empty.
 *Time O(n) & space O(n)
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
		bool isFUll(Node<T>*);
		bool isLeaf(Node<T>*);
		bool isCompleteTree();
		void levelOrderTraversal();
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
/* utility function to check whether given node is full or not */
template <class T> bool Tree<T>:: isFUll(Node<T>* current){
	if(current->leftChild && current->rightChild)
		return true;
	return false;
}
/*checks whether a tree is complete binary tree or not*/
template <class T> bool Tree<T>:: isCompleteTree(){
	Node<T> *current;
	queue<Node<T>*> Q;
	bool fullNode=true;
	Q.push(this->root);
	while(!Q.empty()){
		current=Q.front();
		/* Once a node is encountered which is not full following all nodes should be leaf nodes*/
		if(!fullNode){
			if(!this->isLeaf(current))
				return false;
		}
		/* after encountering the first node who is not full fullNode is set to false always*/
		if(fullNode && !this->isFUll(current)){
			fullNode=false;
			if(!current->leftChild && current->rightChild)	//if  the first half node contains only right child
				return false;
		}
		if(current->leftChild)
			Q.push(current->leftChild);
		if(current->rightChild)
			Q.push(current->rightChild);
		Q.pop();
	}
	return true;
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
	if(tree.isCompleteTree())
		OUT("Given Tree is Complete");
	else OUT("Given Tree is NOT Complete");
	OUT(endl);
}
