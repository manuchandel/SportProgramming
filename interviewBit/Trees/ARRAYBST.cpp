/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* create a Height Balanced BST from given sorted array */
TreeNode* createTree(const vector<int> &A,int i,int j){
    if(i>j)
        return NULL;
    int mid=(i+j)>>1;
    TreeNode *treenode=new TreeNode(A[mid]);
    if(i==j)
        return treenode;
    treenode->left=createTree(A,i,mid-1);
    treenode->right=createTree(A,mid+1,j);
    return treenode;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return createTree(A,0,A.size()-1);
}
