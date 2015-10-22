/*
 *The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two nodes in the tree.
 *Diameter of tree takes O(n)
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
		int height;
		T data;	
};
template <class T> Node<T> :: Node(){
	this->leftChild=this->rightChild=NULL;
	this->height=0;
}
template <class T> class Tree{
	public:
		Tree();
		Node<T>* makeTree(string,string,int&,int,int);
		void deleteTree(Node<T>*);
		int heightOfTree(Node<T>*);
		void postorderTraversal(Node<T>*);
		int diameterOfTree(Node<T>*);
		Node<T>*root;

};
template <class T> Tree<T> :: Tree(){
	this->root=NULL;
}
/* assigns height of maximum subtree rooted at each node */
template <class T> int Tree<T> ::heightOfTree(Node <T>* current){
	if(!current)
		return 0;
	current->height=1+max(heightOfTree(current->leftChild),heightOfTree(current->rightChild));
	return current->height;
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
/* returns diameter of tree */
template <class T> int Tree<T>:: diameterOfTree(Node<T>* current){
	if(!current)
		return 0;
	int lh,rh;
	if(current->leftChild)
		lh=current->leftChild->height;
	else lh=0;
	if(current->rightChild)
		rh=current->rightChild->height;
	else rh=0;
	return max(lh+rh+1,max(diameterOfTree(current->leftChild),diameterOfTree(current->rightChild)));
}
int main(){
	int i;
	string preorderBuffer;
	string inorderBuffer;
	Tree <char> tree;
	cin>>preorderBuffer;	//enter preorder traversal
	cin>>inorderBuffer;	//enter inorder traversal
	i=0;
	tree.makeTree(preorderBuffer,inorderBuffer,i,0,preorderBuffer.length()-1);
	tree.heightOfTree(tree.root);
	printf("%d\n",tree.diameterOfTree(tree.root));
	
}
