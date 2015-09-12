/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int index(int s,int end,vector<int> &inorder,int val){
    for(int i=s;i<=end;i++)
        if(inorder[i]==val)
            return i;
    return -1;
}
TreeNode* makeTree(int &i,int b,int e,vector<int> &inorder,vector<int> &postorder){
    if(b>e){
        i+=1;
        return NULL;
    }
    TreeNode* A=new TreeNode(postorder[i]);
    if(b==e)
        return A;
    int j=index(b,e,inorder,postorder[i]);
    i-=1;
    A->right=makeTree(i,j+1,e,inorder,postorder);
    i-=1;
    A->left=makeTree(i,b,j-1,inorder,postorder);
    return A;
    
}
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    int i=postorder.size()-1;
    return makeTree(i,0,i,inorder,postorder);
}
