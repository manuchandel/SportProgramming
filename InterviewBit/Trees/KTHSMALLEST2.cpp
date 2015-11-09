/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool kth(TreeNode *t,int k,int &smallest,int &i){
    if(!t)
        return 0;
    bool l=kth(t->left,k,smallest,i);
    if(l)
        return 1;
    i=i+1;
    smallest=t->val;
    if(i==k)
        return 1;
    return kth(t->right,k,smallest,i);
    
    
}
int Solution::kthsmallest(TreeNode* root, int k) {
    int i=0;
    int smallest=0;
    kth(root,k,smallest,i);
    return smallest;
}
