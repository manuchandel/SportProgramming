/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool swappedValue(TreeNode *A,TreeNode **previous,vector<int> &v){
    if(!A)
        return 0;
    bool l=swappedValue(A->left,previous,v);
    if(l)return 1;
    if(!(*previous)){
        *previous=A;
    }else if(A->val<(*previous)->val){
        v.push_back((*previous)->val);
       return 1;
    }
    *previous=A;
    return swappedValue(A->right,previous,v);
}
bool swappedValue2(TreeNode *A,TreeNode **previous,vector<int> &v){
    if(!A)
        return 0;
    bool l=swappedValue2(A->right,previous,v);
    if(l)return 1;
    if(!(*previous)){
        *previous=A;
    }
    else if(A->val>(*previous)->val){
        v.push_back((*previous)->val);
       return 1;
    }
    *previous=A;
    return swappedValue2(A->left,previous,v);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> v;
    TreeNode *B=NULL;
    swappedValue(A,&B,v);
    B=NULL;
    swappedValue2(A,&B,v);
    sort(v.begin(),v.end());
    return v;
}
