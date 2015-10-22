/*
 *Given a Binary Tree and a key, write a function that prints all ancestors of the key k
 *printAncestors() takes O(n)
 *Constructing tree takes O(n^2)
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
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
		T data;	
};
template <class T> Node<T> :: Node(){
	this->leftChild=this->rightChild=NULL;
}
template <class T> class Tree{
	public:
		Tree();
		Node<T>* makeTree(string,string,int&,int,int);
		void deleteTree(Node<T>*);
		bool printAncestors(Node<T>*,T);
		void postorderTraversal(Node<T>*);
		Node<T>*root;

};
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
}
/* prints all ancestors of key k in tree*/
template <class T> bool Tree<T>:: printAncestors(Node<T>*current,T key){
	if(!current)
		return false;
	else if(current->data==key)
		return true;
	else if(printAncestors(current->leftChild,key)||printAncestors(current->rightChild,key)){
		OUT(current->data<<" ");
		return true;
	}
	return false;
}
template <class T> void Tree<T>:: postorderTraversal(Node<T>*current){
	if(!current)
		return;
	this->postorderTraversal(current->leftChild);
	this->postorderTraversal(current->rightChild);
	cout<<current->data<<" ";	
}
template<class T> void Tree<T>::deleteTree(Node<T>*current){
	if(!current)
		return;
	deleteTree(current->leftChild);
	deleteTree(current->rightChild);
	delete current;
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
		deleteTree(this->root);
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
	char k;
	string preorderBuffer;
	string inorderBuffer;
	Tree <char> tree;
	IN(preorderBuffer);	//input preorder traversal
	IN(inorderBuffer);	//input inorder traversal
	IN(k);
	i=0;	
	tree.makeTree(preorderBuffer,inorderBuffer,i,0,preorderBuffer.length()-1);	//create tree according to traversals
	tree.printAncestors(tree.root,k);
	OUT(endl);
}
