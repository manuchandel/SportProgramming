/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* Given two binary trees, write a function to check if they are equal or not. */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A && !B)
        return 0;
    if(!A && B)
        return 0;
    if(!A)
        return 1;
    if(A->val==B->val)
        return (this->isSameTree(A->left,B->left))&
                    (this->isSameTree(A->right,B->right));
    else return 0;
}
