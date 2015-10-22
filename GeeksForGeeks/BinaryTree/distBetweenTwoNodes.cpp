/*
 *Given a Binary Tree (BT), Print distance between two nodes
 *Time O(n) & space O(1)
 *
 */
#include <iostream>
#include <cstdlib>
#include <math.h>
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
/* returns pointer to the common ancestor */
template <class T> Node<T>* lca(Node<T> *current,T a,T b){
	if(!current)
		return NULL;
	if(current->data==a || current ->data==b)
		return current;
	Node<T> *left=lca(current->leftChild,a,b);
	Node<T> *right=lca(current->rightChild,a,b);
	if(left && right)
		return current;
	else if(left)
		return left;
	return right;
}
/* find dist util function return distance to a node with data a */
template <class T> int findDistUtil(Node<T> *current,T a,int level){
	if(!current)
		return 0;
	if(current->data==a)
		return level;
	return max(findDistUtil(current->leftChild,a,level+1),findDistUtil(current->rightChild,a,level+1));
}
/* find dist util function return distance to a node with pointer key */
template <class T> int findDistUtil(Node<T> *current,Node<T> *key,int level){
	if(!current)
		return 0;
	if(current==key)
		return level;
	return max(findDistUtil(current->leftChild,key,level+1),findDistUtil(current->rightChild,key,level+1));
}
/* distance(a,b)=distance(root,a)+distance(root,b)-2*distance(root,ancestor) */
template <class T> int findDist(Tree<T> &tree,T a,T b){
	int adist=findDistUtil(tree.root,a,0);
	int bdist=findDistUtil(tree.root,b,0);
	int cdist=findDistUtil(tree.root,lca(tree.root,a,b),0);
	OUT(adist+bdist-2*cdist);
	OUT(endl);
	return (adist+bdist-2*cdist);
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
	int a,b;
	//while(1){
		IN(a);
		IN(b);
		findDist(tree,a,b);
	//}
}
