/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int maxindex(int b,int e,vector<int> &A){
    int i;
    int maxi=b;
    for(i=b+1;i<=e;i++){
        if(A[maxi]<A[i])
            maxi=i;
    }
    return maxi;
}
TreeNode* makeTree(int b,int e,vector<int> &A){
    if(b>e)
        return NULL;
    int j=maxindex(b,e,A);
    TreeNode *treenode=new TreeNode(A[j]);
    treenode->left=makeTree(b,j-1,A);
    treenode->right=makeTree(j+1,e,A);
    return treenode;
    
}
TreeNode* Solution::buildTree(vector<int> &A) {
    return makeTree(0,A.size()-1,A);
}
