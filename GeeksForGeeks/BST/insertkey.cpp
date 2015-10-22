Node* createNode(int key){
	Node *node=new Node();
	node->data=key;
	return node;
}
/* 
 *first it searches for the place node should be if its not there than inserts it there 
 *New node inserted is always a leaf
 *uses binary tree property to search key if not found returns null
 *Time =O(n) in  worst case & no extra space
 */
bool insert(Node *current,int key){
	if(!current)
		return 0;
	if(current->data==key)
		return true;
	else if(current->data > key){
		if(!insert(current->leftChild,key))
			current->leftChild=createNode(key);
		}
	else if(current->data <key){
		if(!insert(current->rightChild,key))
			current->rightChild=createNode(key);
		}
	return true;
}
