/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void preorder(vector<int> &v,TreeNode *A){
    if(!A)
        return;
    v.push_back(A->val);
    preorder(v,A->left);
    preorder(v,A->right);
}
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> v;
    preorder(v,A);
    return v;
}
