/* 
 *uses binary tree property to search key if not found returns null
 *Time =O(n) in  worst case & no extra space
 */
Node* search(Node *current,int key){
	if(!current)
		return NULL;
	if(current->data==key)
		return current;
	else if(current->data > key)
			return search(current->leftChild,key);
	else return search(current->rightChild,key);
}
