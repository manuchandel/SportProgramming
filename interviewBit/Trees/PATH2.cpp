/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* 
 *Given a binary tree and a sum,
 *find all root-to-leaf paths where each path’s sum equals the given sum.
 */
void findPaths(vector<vector<int>> &v, vector<int> &row,
                TreeNode *current,int sum,int B){
    if(!current)
        return;
    if(!current->left && !current->right){
        sum+=current->val;
        if(sum==B){
            row.push_back(current->val);
            v.push_back(row);
            row.pop_back();
        }
        return;
    }
    sum+=current->val;
    row.push_back(current->val);
    findPaths(v,row,current->left,sum,B);
    findPaths(v,row,current->right,sum,B);
    row.pop_back();
}
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    vector<vector<int>> v;
    vector<int> row;
    findPaths(v,row,root,0,sum);
    return v;
}
