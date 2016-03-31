/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    queue<TreeNode*> Q;
    queue<int> L;
    if(A){
        Q.push(A);
        L.push(0);
    }
    vector<vector<int>> v;
    vector<int> r;
    while(!Q.empty()){
        TreeNode *T=Q.front();
        int l=L.front();
        if(v.size()!=l+1){
            v.push_back(r);
        }
        if(T->left){
            Q.push(T->left);
            L.push(l+1);
        }
        if(T->right){
            Q.push(T->right);
            L.push(l+1);
        }
        v[l].push_back(T->val);
        Q.pop();
        L.pop();
    }
    return v;
}
