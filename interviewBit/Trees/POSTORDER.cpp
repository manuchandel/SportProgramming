/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void postorder(vector<int> &v,TreeNode *A){
    if(!A)
        return;
    postorder(v,A->left);
    postorder(v,A->right);
    v.push_back(A->val);
}
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> v;
    postorder(v,A);
    return v;
        
}
