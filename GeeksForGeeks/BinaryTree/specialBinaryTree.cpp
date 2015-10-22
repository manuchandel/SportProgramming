/*
 *Given Inorder Traversal of a Special Binary Tree in which key of every node is greater than keys in left and right children.
 *construct the Binary Tree and return root.
 *Time O(nlogn) & Space O(n)
 */
#include <iostream>
#define IN(a) cin>>a
#define OUT(a) cout<<a
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
int *arr;	//array to store elements in inorder
/* returns index of maximum element */
int modifiedMax(int a,int b){
	if(arr[a]<arr[b])
		return b;
	return a;
}
class Node{
	public:
		Node();
		Node*leftChild,*rightChild;
		int data;	
};
Node:: Node(){
	this->leftChild=this->rightChild=NULL;
}
class Segtree{
	public:
		Segtree();
		Node *root;
		Node* buildSegTree(int,int);
		int getMaxIndex(Node*,int,int,int,int);
};
/* implementation of class segTree functions */
Segtree :: Segtree(){
	this->root=NULL;
}
/* builds segTree which stores index of maximum element in Given range  O(n)*/
Node* Segtree :: buildSegTree(int l,int r){
	Node *node=new Node();
	if(l==r){
		node->data=l;
		return node;
	}
	int mid=(l+r)>>1;
	node->leftChild=buildSegTree(l,mid);
	node->rightChild=buildSegTree(mid+1,r);
	node->data=modifiedMax(node->leftChild->data,node->rightChild->data);
	return node;
}
/* returns maximum index in given range */
int Segtree:: getMaxIndex(Node *current,int l,int r,int start,int end){
	int mid=(start+end)>>1;
	int li,ri;
	if(l==start && r==end)
		return current->data;
	else if(l>mid)
		return getMaxIndex(current->rightChild,l,r,mid+1,end);
	else if(r<=mid)
		return getMaxIndex(current->leftChild,l,r,start,mid);
	else{
		li=getMaxIndex(current->leftChild,l,mid,start,mid);
		ri=getMaxIndex(current->rightChild,mid+1,r,mid+1,end);
		return modifiedMax(li,ri);
	}
}
class Tree{
	public:
		Tree();
		void postOrderTraversal(Node*);
		Node* buildSpecialTree(Segtree*,int,int,int);
		Node *root;

};
/* implementation of class Tree functions*/
Tree:: Tree(){
	this->root=NULL;
}
/* prints post order traversal */
void Tree:: postOrderTraversal(Node *current){
	if(!current)
		return;
	postOrderTraversal(current->leftChild);
	postOrderTraversal(current->rightChild);
	OUT(current->data);
	OUT(" ");
}
/*builds special binary tree from given array O(nlogn)*/
Node* Tree:: buildSpecialTree(Segtree *segtree,int l,int r,int n){
	if(l>r)
		return NULL;
	Node *node=new Node();
	int ri=segtree->getMaxIndex(segtree->root,l,r,0,n-1);	//ri(root index) query takes O(logn)
	node->data=arr[ri];
	node->leftChild=buildSpecialTree(segtree,l,ri-1,n);
	node->rightChild=buildSpecialTree(segtree,ri+1,r,n);
	return node;
}

int main(){
	int i;		//loop variable
	int n;
	IN(n);	//no of elements
	arr=new int[n];	//array containing elements in inorder
	FOR(i,n)
		IN(arr[i]);	//input element
	Segtree segtree;
	Segtree *ptr=&segtree;
	ptr->root=ptr->buildSegTree(0,n-1);	//building segtree takes O(n)
	Tree tree;
	tree.buildSpecialTree(ptr,0,n-1,n);	//building special tree takes O(nlogn)
	tree.postOrderTraversal(tree.root);
	OUT(endl);
}
