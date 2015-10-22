/*
 *vetex cover of a binary tree
 *The idea is to consider following two possibilities for root and recursively for all nodes down the root.
 *1) Root is part of vertex cover: In this case root covers all children edges.
 *We recursively calculate size of vertex covers for left and right subtrees and add 1 to the result (for root).
 *2) Root is not part of vertex cover: In this case, both children of root must be included in vertex cover to cover all root to children edges.
 *We recursively calculate size of vertex covers of all grandchildren and number of children to the result (for two children of root).
 *vertexCover() takes O(n)
*/
#include <iostream>
#include <cstdio>
#define IN(a) cin>>a
#define OUT(a) cout<<a
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
int min(int a,int b){
	if(b<a)
		return b;
	return a;
}
template <class T> class Node{
	public:
		Node();
		Node<T> *leftChild,*rightChild;
		T data;
		int v;	//stores the vertex cover of subtree rooted at node
};
template <class T> Node<T> :: Node(){
	this->leftChild=this->rightChild=NULL;
	this->v=0;
}
template <class T> class Tree{
	public:
		Tree();
		Node<T>* makeTree(string,string,int&,int,int);
		int vertexCover(Node<T>*);
		Node<T>*root;

};
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
}
/*deletes leafnodes whose distance from root is less than k*/
template <class T> int Tree<T>:: vertexCover(Node<T>*current){
	if(!current)
		return 0;
	else if(!current->leftChild && !current->rightChild)
		return 0;
	else if(current->v > 0)
		return current->v;
	int n1,n2=0,n3=0;
	/* if root is a part than */
	n1=1+vertexCover(current->leftChild)+vertexCover(current->rightChild);
	/* if root is not the part */
	if(current->leftChild)
		n2=1+vertexCover(current->leftChild->leftChild)+vertexCover(current->leftChild->rightChild);
	if(current->rightChild)
		n3=1+vertexCover(current->rightChild->leftChild)+vertexCover(current->rightChild->rightChild);
	current->v=min(n1,n2+n3);
	return current->v;	
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
	OUT(tree.vertexCover(tree.root));
	OUT(endl);
}
