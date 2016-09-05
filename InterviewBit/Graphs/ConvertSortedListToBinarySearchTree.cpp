/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
TreeNode * getNode(int x){
    TreeNode *newnode=new TreeNode(x);
    return newnode;
}
TreeNode * foo(ListNode *A){
    if(!A)
        return NULL;
    ListNode *tortoise=A;
    ListNode *hare=A;
    ListNode *prev=NULL;
    while(hare){
        // is not last
        if(hare->next){
            hare=hare->next;
            if(hare->next){ // is not last
                hare=hare->next;
                prev=tortoise;
                tortoise=tortoise->next;
            }else hare=NULL;
        }else hare=NULL;
    }
    
    TreeNode *root=getNode(tortoise->val);
    root->right=foo(tortoise->next);
    if(prev){
        prev->next=NULL;
        root->left=foo(A);
    }
    return root;
    
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    return foo(A);
}
