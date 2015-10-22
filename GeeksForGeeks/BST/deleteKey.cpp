/* Time O(n) in worst case and no extra space */

/* this function deletes a leaf whose value is leafkey */
Node* deleteLeaf(Node *current, int leafkey){
	if(!current)
		return NULL;
	else if(current->data==leafkey){
		free(current);
		return NULL;
	}else if(current->data > leafkey)
		current->leftChild=deleteLeaf(current->leftChild,leafkey);
	else if(current->data < leafkey)
		current->rightChild=deleteLeaf(current->rightChild,leafkey);
	return current;
}
/* this function deletes a node whose value is leafkey */
Node* deleteKey(Node *start,int key){
	Node *target=search(start,key);
	Node *current=target;
	if(!target)
		return start;
	if(!target->rightChild && !target->leftChild)	//if target node is leaf node
		start=deleteLeaf(start,key);
	else if(target->leftChild && !target->rightChild){	//if target node have only left child
		current=target->leftChild;
		target->data=current->data;
		target->leftChild=current->leftChild;
		target->rightChild=current->rightChild;
		free(current);
	}
	else if(target->rightChild && !target->leftChild){	//if target node have only right child
		current=target->rightChild;
		target->data=current->data;
		target->leftChild=current->leftChild;
		target->rightChild=current->rightChild;
		free(current);
	}else{							//if target node have both children
		current=target->leftChild;
		while(current){
			key=current->data;
			current=current->rightChild;
		}
		target->data=key;
		target->leftChild=deleteKey(target->leftChild,key);
	}
	return start;
}
/* call tree.root=deleteNode(tree.root,key) */
