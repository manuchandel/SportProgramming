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
 *Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *Find the total sum of all root-to-leaf numbers % 1003.
 */
int evaluate(vector<int> &v){
    int n=v.size();
    int ten=1;
    int sum=0;
    int temp;
    for(int i=n-1;i>=0;i--){
        temp=ten*v[i];
        temp%=1003;
        sum=sum+temp;
        sum%=1003;
        ten*=10;
        ten%=1003;
    }
    return sum;
}
void sumN(TreeNode *A,vector<int> &row,int &sum){
    if(!A)
        return;
    if(!A->left && !A->right){
        row.push_back(A->val);
        sum+=evaluate(row);
        sum%=1003;
        row.pop_back();
        return;
    }
    row.push_back(A->val);
    sumN(A->left,row,sum);
    sumN(A->right,row,sum);
    row.pop_back();
}
int Solution::sumNumbers(TreeNode* A) {
    int sum=0;
    vector<int>row;
    sumN(A,row,sum);
    return sum;
}
