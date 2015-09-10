/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(vector<int> &v,TreeNode *A){
    if(!A)
        return;
    inorder(v,A->left);
    v.push_back(A->val);
    inorder(v,A->right);
}
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> v;
    inorder(v,A);
    return v;
}
