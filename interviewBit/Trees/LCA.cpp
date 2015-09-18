/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int callca(TreeNode *A,int val1,int val2){
    if(!A)
        return -1;
    if(A->val==val1 || A->val==val2)
        return A->val;
    int l=callca(A->left,val1,val2);
    int r=callca(A->right,val1,val2);
    if(l!=-1 && r!=-1)
        return A->val;
    else if(l!=-1)
        return l;
    else return r;
}
bool present(TreeNode *A,int a){
    if(!A)
        return 0;
    if(A->val==a)
        return 1;
    return (present(A->left,a) | present(A->right,a));
}
int Solution::lca(TreeNode* A, int val1, int val2) {
    if(present(A,val1) && present(A,val2))
        return callca(A,val1,val2);
    return -1;
}
