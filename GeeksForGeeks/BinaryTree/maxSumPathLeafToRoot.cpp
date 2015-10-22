/*
 *Given a Binary Tree, find the maximum sum path from a leaf to root
 *getTargetLeaf() & printAncestors() takes O(n) 
 */
#include <iostream>
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
		Node* getTargetLeaf(Node*,Node*,int,int&);
		bool printAncestors(Node*,Node*);
		Node *root;

};
Tree:: Tree(){
	this->root=NULL;
}
Node* Tree:: createNode(int key){
	Node *node=new Node();
	node->data=key;
	return node;
}
/* prints all ancestors of leaf node pointed by leaf */
bool Tree:: printAncestors(Node *current,Node *leaf){
	if(!current)
		return false;
	else if(current==leaf || printAncestors(current->leftChild,leaf) || printAncestors(current->rightChild,leaf)){
		OUT(current->data);
		OUT(" ");
		return true;
	}else return false;
}
/*returns pointer to leaf node such that root to leaf sum is maximum*/
Node* Tree:: getTargetLeaf(Node *current,Node* leaf,int currentSum,int &maxSum){
	if(!current)
		return leaf;
	if(!current->leftChild && !current->rightChild){
		if(current->data+currentSum>maxSum){
			maxSum=currentSum+current->data;
			return current;
		}else return leaf;
	}
	leaf=getTargetLeaf(current->leftChild,leaf,currentSum+current->data,maxSum);
	leaf=getTargetLeaf(current->rightChild,leaf,currentSum+current->data,maxSum);
	return leaf;
}
int main(){
	int i=0;
	Tree tree;
	/* creating sample tree*/
	tree.root=tree.createNode(10);
	tree.root->leftChild=tree.createNode(-2);
	tree.root->rightChild=tree.createNode(7);
	tree.root->leftChild->leftChild=tree.createNode(8);
	tree.root->leftChild->rightChild=tree.createNode(-4);
	Node *leaf=tree.getTargetLeaf(tree.root,NULL,0,i);
	tree.printAncestors(tree.root,leaf);
	OUT(endl);
}
