/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* find minimum depth of binary Tree */
int depth(TreeNode *A){
    if(!A)
        return INT_MAX;
    if(!A->left && !A->right)
        return 1;
    return 1+min(depth(A->left),depth(A->right));
}
int Solution::minDepth(TreeNode* A) {
    return depth(A);
}
