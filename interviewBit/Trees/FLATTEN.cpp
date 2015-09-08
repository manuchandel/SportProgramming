/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void flat(TreeNode* A,TreeNode **previous){
    if(!A)
        return;
    TreeNode *R=A->right;
    if(*previous){
        (*previous)->right=A;
        (*previous)->left=NULL;
    }
    *previous=A;
    flat(A->left,previous);
    flat(R,previous);
    
    
}
TreeNode* Solution::flatten(TreeNode* A) {
    if(!A)
        return A;
    TreeNode *current=NULL;
    flat(A,&current);
    return A;
}
