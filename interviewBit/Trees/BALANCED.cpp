/*
 *Given a binary tree, determine if it is height-balanced.
 */
/*
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode *A){
    if(!A)
        return 0;
    if(!(A->left) && !(A->right))
        return 1;
    int lh=1+height(A->left);
    int rh=1+height(A->right);
    if(lh<0 || rh<0)
        return INT_MIN;
    if(abs(lh-rh)>1)
        return INT_MIN;
    return max(lh,rh);
    
}
int Solution::isBalanced(TreeNode* A) {
    if(height(A)<0)
        return 0;
    return 1;
   
}
