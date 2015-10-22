/*
 *Add all greater values to every node in a given BST
 *Time =O(n) & no extra space
 */
void addSum(Node *current,int &sum){
	if(!current)
		return;
	addSum(current->rightChild,sum);
	sum+=current->data;
	current->data=sum;
	addSum(current->leftChild,sum);
}
/*
 *int sum=0;
 *call addsum(tree.root,sum);
 */
