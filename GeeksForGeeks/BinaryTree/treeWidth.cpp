/*
 *Given a binary tree, write a function to get the maximum width of the given tree.
 *Width of a tree is maximum of widths of all levels.
 *Width at a level is number of nodes in that level
 *width() takes O(n) time and O(h) extra space where h=maximum height of a tree
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
		int width();
		int height(Node<T>*);
		void postorderTraversal(Node<T>*);
		Node<T>*root;

};
/* auxilary function that stores widths at different levels */
template <class T> void auxilary(Node <T>* current,int arr[],int level){
	if(!current)
		return;
	//printf("%d\n",level);
	arr[level]++;
	auxilary(current->leftChild,arr,level+1);
	auxilary(current->rightChild,arr,level+1);
}
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
}
/* this function returns maximum height of the tree considering root at level 1*/
template <class T> int Tree<T> ::height(Node <T>* current){
	if(!current)
		return 0;
	return 1+max(height(current->leftChild),height(current->rightChild));
}
/* function which returns maximum width of binary tree*/
template <class T> int Tree<T>:: width(){
	int i;	//loop variable
	int maxWidth=0;
	int maxheight=this->height(this->root);
	int nodeCount[maxheight+1];
	FOR(i,maxheight+1)
		nodeCount[i]=0;
	auxilary(this->root,nodeCount,1);
	FOR(i,maxheight+1)
		maxWidth=max(maxWidth,nodeCount[i]);
	return maxWidth;
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
	printf("%d\n",tree.width());	
}
