/*
 *Given a Binary Tree, write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST).
 *If the complete Binary Tree is BST, then return the size of whole tree.
 *Here subtree refres to classic subtree most commonly intepreted definition
 *If a node is in subtree than all its decendants in big tree must be in subtree
 *Time O(n) and no extra space if stack space is neglected
 */
struct Tupple{
	int size,min,max;
	bool isbst;
};
Tupple setT(int a,int b,int c,bool f){
	Tupple tupple;
	tupple.size=a;
	tupple.min=b;
	tupple.max=c;
	tupple.isbst=f;
	return tupple;
}
Tupple bstsize(Node *current){
	if(!current)
		return setT(0,INT_MAX,INT_MIN,1);
	Tupple left=bstsize(current->leftChild);
	Tupple right=bstsize(current->rightChild);
	if(left.isbst && right.isbst){
		if(current->data < right.min && current->data >left.max){
			if(current->leftChild && current->rightChild)
				return setT(left.size+right.size+1,left.min,right.max,1);
			else if(current->leftChild)
				return setT(left.size+1,left.min,current->data,1);
			else if(current->rightChild)
				return setT(right.size+1,current->data,right.max,1);
			else return setT(1,current->data,current->data,1);
		}
	}
	if(left.size >= right.size){
			left.isbst=0;
			return left;
	}
	else if(right.size > left.size){
			right.isbst=0;
			return right;
	}
}
/* call bstsize(tree.root).size; */
