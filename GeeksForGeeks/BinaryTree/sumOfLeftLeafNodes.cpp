/*
 *Find sum of all left leaves in a given Binary Tree
 *sum() takes O(n)
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define IN(a) cin>>a
#define OUT(a) cout<<a
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
class Node{
	public:
		Node();
		Node*leftChild,*rightChild;
		int data;	
};
Node:: Node(){
	this->leftChild=this->rightChild=NULL;
}
class Tree{
	public:
		Tree();
		Node* createNode(int);
		int sum(Node*,bool);
		Node*root;

};
Tree:: Tree(){
	this->root=NULL;
}
Node* Tree:: createNode(int key){
	Node *node=new Node();
	node->data=key;
	return node;
}
/*returns sum of left leafnodes*/
int Tree:: sum(Node *current,bool isleft){
	if(!current)
		return 0;
	if(!current->leftChild && !current->rightChild && isleft)
		return current->data;
	return sum(current->leftChild,true)+sum(current->rightChild,false);
}
int main(){
	int i;
	Tree tree;
	/* creating sample tree*/
	tree.root=tree.createNode(20);
	tree.root->leftChild=tree.createNode(9);
	tree.root->rightChild=tree.createNode(19);
	tree.root->leftChild->leftChild=tree.createNode(5);
	tree.root->rightChild->leftChild=tree.createNode(23);
	tree.root->leftChild->rightChild=tree.createNode(15);
	tree.root->rightChild->rightChild=tree.createNode(52);
	tree.root->leftChild->rightChild->rightChild=tree.createNode(15);
	tree.root->rightChild->rightChild->leftChild=tree.createNode(50);
	OUT(tree.sum(tree.root,0));
	OUT(endl);
}
