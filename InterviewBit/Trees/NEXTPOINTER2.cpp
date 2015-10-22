/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode *current;
    TreeLinkNode *prev=0;
    queue<TreeLinkNode*> Q;
    queue<int> level;
    if(A){
        Q.push(A);
        level.push(0);
    }
    int thislevel=0;
    int prevlevel=0;
    while(!Q.empty()){
        thislevel=level.front();
        current=Q.front();
        if(thislevel!=prevlevel){
            if(prev)
                prev->next=0;
        }
        else{
            if(prev)
                prev->next=current;
        }
        if(current->left){
            Q.push(current->left);
            level.push(thislevel+1);
        }
        if(current->right){
            Q.push(current->right);
            level.push(thislevel+1);
        }
        prevlevel=thislevel;
        prev=current;
        Q.pop();
        level.pop();
    }
    if(prev)
        prev->next=0;
    
}
