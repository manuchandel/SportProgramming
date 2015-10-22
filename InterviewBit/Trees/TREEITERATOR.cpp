/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode *current=NULL;
void threadedBST(TreeNode *A,TreeNode **previous){
    if(!A)
        return;
    threadedBST(A->left,previous);
    if(*previous)
        (*previous)->right=A;
    *previous=A;
    threadedBST(A->right,previous);
    
}
BSTIterator::BSTIterator(TreeNode *root) {
    current=root;
    while(current && current->left) current=current->left;
    TreeNode *B=NULL;
    threadedBST(root,&B);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(current)
        return 1;
    return 0;
}

/** @return the next smallest number */
int BSTIterator::next() {
    int a=current->val;
    current=current->right;
    return a;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
