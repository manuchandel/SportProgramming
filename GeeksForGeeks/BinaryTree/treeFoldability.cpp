/*
 *Given a binary tree, find out if the tree can be folded or not.
 *A tree can be folded if left and right subtrees of the tree are structure wise mirror image of each other.
 *An empty tree is considered as foldable
 *foldable() takes O(n) time
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
		void foldable(Node<T>*,Node<T>*);
		void postorderTraversal(Node<T>*);
		Node<T>*root;

};
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
}
/* utility function which checks whether structure is same */
template <class T> bool checkStruct(Node<T>*l,Node<T>*r){
	if(!l || !r)
		return false;
	else if(l->leftChild && !r->rightChild)
		return false;
	else if(!l->leftChild && r->rightChild)
		return false;
	else if(l->rightChild && !r->leftChild)
		return false;
	else if(!l->rightChild && r->leftChild)
		return false;
	else return true;
}
/* function checks whether given binary tree is foldable */
template <class T> void Tree<T>:: foldable(Node<T>*left,Node<T>*right){
	if(!left && !right)
		return;
	if(!checkStruct(left,right)){
		printf("Given Tree is not foldable\n");
		exit(0);
	}
	foldable(left->leftChild,right->rightChild);
	foldable(left->rightChild,right->leftChild);
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
	string preorderBuffer;
	string inorderBuffer;
	Tree <char> tree;
	cin>>preorderBuffer;	//input preorder traversal
	cin>>inorderBuffer;		//input inorder traversal
	i=0;	
	tree.makeTree(preorderBuffer,inorderBuffer,i,0,preorderBuffer.length()-1);
	tree.foldable(tree.root->leftChild,tree.root->rightChild);
	printf("Given tree is foldable\n");	
}
