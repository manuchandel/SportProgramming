/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/* Find max Depth Of the binary tree*/
int findMaxDepth(TreeNode *A){
    if(!A)
        return 0;
    return 1+max(findMaxDepth(A->left),findMaxDepth(A->right));
}
int Solution::maxDepth(TreeNode* A) {
    return findMaxDepth(A);
}
