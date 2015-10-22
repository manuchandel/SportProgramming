/*
 *Given a root of a tree, and an integer k. Print all the nodes which are at k distance from root.
 *printNodes() takes O(n)
 *Constructing tree takes O(n^2)
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(int a=0;a<b;a++)
#define LOOP(a,b,c) for(int a=b;a<c;a++)
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
		void printNodes(Node<T>*,int,int);
		void postorderTraversal(Node<T>*);
		Node<T>*root;

};
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
}
/* prints nodes at distance k from root*/
template <class T> void Tree<T>:: printNodes(Node<T>*current,int dist,int k){
	if(!current)
		return;
	if(dist==k){
		cout<<current->data<<endl;
		return;
	}
	printNodes(current->leftChild,dist+1,k);
	printNodes(current->rightChild,dist+1,k);
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
		cout<<"There is error in the traversals"<<endl;
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
	int k;
	string preorderBuffer;
	string inorderBuffer;
	Tree <char> tree;
	cin>>preorderBuffer;	//input preorder traversal
	cin>>inorderBuffer;		//input inorder traversal
	IN(k);
	i=0;	
	tree.makeTree(preorderBuffer,inorderBuffer,i,0,preorderBuffer.length()-1);
	tree.printNodes(tree.root,0,k);
}
