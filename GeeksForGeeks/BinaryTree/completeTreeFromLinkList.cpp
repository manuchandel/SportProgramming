/*
 *Construct Complete Binary Tree from linked list representation
 *linked list representation consist of level order of complete binary Tree
 *Time O(n) & Space=O(n)
*/
#include <iostream>
#include <cstdlib>
#include <queue>
#include <list>
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
		void makeCompleteTree(list<T>&);
		void postorder(Node<T>*);
		Node<T>*root;

};
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
}
/* prints binary tree in post order fashion */
template <class T> void Tree<T>::postorder(Node<T> *current){
	if(!current)
		return;
	postorder(current->leftChild);
	postorder(current->rightChild);
	OUT(current->data<<" ");
}
/* makes complete binary tree from given link list representation */
template <class T> void Tree<T> :: makeCompleteTree(list<T>& L){
	queue<Node<T>*> Q;
	list<int> :: iterator it=L.begin();
	Node<T> *newnode=new Node<T>();
	Node<T>* current;
	newnode->data=*it;
	this->root=newnode;
	Q.push(newnode);
	it++;
	while(it!=L.end()){
		current=Q.front();
		Node<T> *left=new Node<T>();
		current->leftChild=left;
		left->data=*it;
		Q.push(left);
		it++;
		if(it!=L.end()){
			Node<T> *right=new Node<T>();
			current->rightChild=right;
			right->data=*it;
			Q.push(right);
			it++;
		}
		Q.pop();
	}

}

int main(){
	int i,x;
	int n; //no of elements in linklist
	IN(n);	//input no of elements
	Tree <int> tree;
	list <int> L;
	FOR(i,n){
		IN(x);
		L.push_back(x);
	}
	tree.makeCompleteTree(L);	//create tree according to linklist
	tree.postorder(tree.root);	//print all nodes
	OUT(endl);
}
