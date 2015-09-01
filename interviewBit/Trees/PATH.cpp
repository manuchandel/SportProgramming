/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
 *Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
 *such that adding up all the values along the path equals the given sum.
 */
bool isSum(TreeNode *A,int sum,const int &B){
    if(!A)
        return 0;
    sum+=A->val;
    if(!A->left && !A->right){
        if(sum==B)
            return 1;
        return 0;
    }
    return (isSum(A->left,sum,B)|isSum(A->right,sum,B));
    
}
int Solution::hasPathSum(TreeNode* A, int B) {
    return isSum(A,0,B);
}
