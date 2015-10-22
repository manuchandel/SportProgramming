/*
*Given a Binary Search Tree (BST) and a range [min, max], remove all keys which are outside the given range.
*The modified tree should also be BST.
*Time =O(n) & space=O(1)
*/


/* deletes whole tree which is rooted at current */
Node* deleteTree(Node *current){
	if(!current)
		return NULL;
	deleteTree(current->leftChild);
	deleteTree(current->rightChild);
	free(current);
	NULL;
}
/* Trims tree to remove values which do not lie in range [a,b] */
Node* trimTree(Node *current,int a,int b){
	if(!current)
		return NULL;
	Node *p;
	if(current->data > b){
		current->rightChild=deleteTree(current->rightChild);
		if(current->leftChild){ 
			p=current->leftChild;
			current->data=p->data;
			current->leftChild=p->leftChild;
			current->rightChild=p->rightChild;
			free(p);
			return trimTree(current,a,b);
		}else {
			free(current);
			return NULL;
		}
	}else if(current->data < a){
		current->leftChild=deleteTree(current->leftChild);		
		if(current->rightChild){
			p=current->rightChild;
			current->data=p->data;
			current->leftChild=p->leftChild;
			current->rightChild=p->rightChild;
			free(p);
			return trimTree(current,a,b);
		}else {
			free(current);
			return NULL;
		}
	}else {
		current->leftChild=trimTree(current->leftChild,a,b);
		current->rightChild=trimTree(current->rightChild,a,b);
		return current;
	}
}
/* call tree.root=trimTree(tree.root,a,b) */
