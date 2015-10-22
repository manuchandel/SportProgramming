/*
 *Given a Binary Tree, find size of the Largest Independent Set(LIS) in it.
 *A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset
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
		int independentSet(Node<T>*);
		void updateIndependentSet(Node<T>*,vector<T>&);
		Node<T> *root;
		T *pre;
		T *in;

};
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
}
/* uses dynamic programming tecnique to find maximum independent set */
template <class T> int Tree<T>:: independentSet(Node<T>* current){
	if(!current)
		return 0;
	if(current->indepsum > -1)
		return current->indepsum;

	int inclcurrent=1,exclcurrent=0;
	/* if this node is a part */
	if(current->leftChild)
		inclcurrent+=independentSet(current->leftChild->leftChild)+independentSet(current->leftChild->rightChild);
	if(current->rightChild)
		inclcurrent+=independentSet(current->rightChild->leftChild)+independentSet(current->rightChild->rightChild);
	/* if this node is not part */
	exclcurrent=independentSet(current->leftChild)+independentSet(current->rightChild);
	current->indepsum=max(inclcurrent,exclcurrent);
	return current->indepsum;
}
/* Pushes elements of independentSet in inorder fashion into vector A */
template <class T> void Tree<T> :: updateIndependentSet(Node<T> *current,vector<T> &A){
	if(!current)
		return;
	int inclcurrent=1,exclcurrent=0;
	if(current->leftChild)
		inclcurrent+=independentSet(current->leftChild->leftChild)+independentSet(current->leftChild->rightChild);
	if(current->rightChild)
		inclcurrent+=independentSet(current->rightChild->leftChild)+independentSet(current->rightChild->rightChild);
	exclcurrent=independentSet(current->leftChild)+independentSet(current->rightChild);
	if(inclcurrent > exclcurrent){
		//	A.push_back(current->data);	 preorder
		if(current->leftChild){
			updateIndependentSet(current->leftChild->leftChild,A);
			updateIndependentSet(current->leftChild->rightChild,A);
		}
		A.push_back(current->data);	// inorder
		if(current->rightChild){
			updateIndependentSet(current->rightChild->leftChild,A);
			updateIndependentSet(current->rightChild->rightChild,A);
		}
		//	A.push_back(current->data);	 postorder
	}
	else{
		updateIndependentSet(current->leftChild,A);
		updateIndependentSet(current->rightChild,A);
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
	OUT(tree.independentSet(tree.root));
	OUT(endl);
	vector<int> A;
	tree.updateIndependentSet(tree.root,A);
	OUT("{ ");
	FOR(i,A.size()-1)
		OUT(A[i]<<", ");
	OUT(A[i]<<" }\n");
}
