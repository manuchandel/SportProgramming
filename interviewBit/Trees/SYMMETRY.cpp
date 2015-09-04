/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* Given a binary tree, check whether it is a mirror of itself */
int symetric(TreeNode *A, TreeNode *B){
    if(!A && B)
        return 0;
    if(!B && A)
        return 0;
    if(!A)
        return 1;
    if(A->val != B->val)
        return 0;
    return (symetric(A->left,B->right)&symetric(A->right,B->left));
    
}
int Solution::isSymmetric(TreeNode* A) {
    return symetric(A,A);
}
