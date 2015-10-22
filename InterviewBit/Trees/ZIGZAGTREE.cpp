/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> v;
    vector<int> row;
    queue<TreeNode*> Q;
    queue<int> level;
    TreeNode* current;
    if(A){
        Q.push(A);
        level.push(0);
    }
    bool rev=0;
    int thislevel=0;
    int prevlevel=0;
    while(!Q.empty()){
        thislevel=level.front();
        current=Q.front();
        if(current->left){
            Q.push(current->left);
            level.push(thislevel+1);
        }
        if(current->right){
            Q.push(current->right);
            level.push(thislevel+1);
        }
        if(thislevel!=prevlevel){
            v.push_back(row);
            row.clear();
        }
        row.push_back(current->val);
        Q.pop();
        level.pop();
        prevlevel=thislevel;
    }
    if(row.size()>0)
        v.push_back(row);
    int n=v.size();
    for(int i=1;i<n;i+=2)
        for(int j=0;j<v[i].size()/2;j++){
            int temp=v[i][j];
            v[i][j]=v[i][v[i].size()-j-1];
            v[i][v[i].size()-j-1]=temp;
        }
    return v;
}
