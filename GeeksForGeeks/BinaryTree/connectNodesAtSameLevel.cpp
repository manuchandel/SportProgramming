/*
 *connect nodes at same level
 *		A--->NULL
 *     / \
 *    B-->C-->NULL
 *   / \   \
 *  D-->E-->F-->NULL
 *Time O(n) & space O(n)
 *
*/
#include <iostream>
#include <cstdlib>
#include <queue>
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
		T data;
};
template <class T> Node<T> :: Node(){
	this->leftChild=this->rightChild=NULL;
	this->next=NULL;
}
template <class T> class Tree{
	public:
		Tree();
		Node<T>* makeTree(int,int&,int,int);
		void connectNodes();
		void levelorder(Node<T>*);
		Node<T> *root;
		T *pre;
		T *in;

};
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
}
/* does level order traversal by using next pointers */
template <class T> void  Tree<T>:: levelorder(Node<T> *current){
	if(!current)
		return;
	Node <T>*temp=current;
	while(temp){
		OUT(temp->data);OUT(" ");
		temp=temp->next;
	}
	OUT(endl);
	if(!current->leftChild)
		levelorder(current->rightChild);
	else levelorder(current->leftChild);

}
template <class T> class info{
	public:
		Node<T> *present;
		int level;
		info(Node<T> *p,int a){
			present=p;
			level=a;
		}
};
template <class T> info<T>* createStruct(Node<T> *current,int a){
	info<T> *obj=new info<T>(current,a);
	return obj;
}
/* connects nodes at same level */
template <class T> void Tree<T>:: connectNodes(){
	Node<T> *current;
	queue <info<T>*> Q;
	int currentLevel=0;
	Q.push(createStruct(this->root,currentLevel));
	while(!Q.empty()){
		current=Q.front()->present;
		currentLevel=Q.front()->level;
		Q.pop();
		if(!Q.empty() && currentLevel==Q.front()->level)
			current->next=Q.front()->present;
		if(current->leftChild)
			Q.push(createStruct(current->leftChild,currentLevel+1));
		if(current->rightChild)
			Q.push(createStruct(current->rightChild,currentLevel+1));
	}
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
int main(){
	int i;
	int n; //no of elements in traversal
	IN(n);	//input no of elements
	Tree <int> tree;
	tree.pre=new int[n];
	tree.in=new int[n];
	FOR(i,n)
		IN(tree.pre[i]);	//input preorder traversal
	FOR(i,n)
		IN(tree.in[i]);	//input inorder traversal
	i=0;
	tree.root=tree.makeTree(n,i,0,n-1);	//create tree according to traversals
	tree.connectNodes();	//connect nodes at same level
	tree.levelorder(tree.root);	//print level order traversal
}
