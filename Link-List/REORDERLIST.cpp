/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*
  *Given a singly linked list
  *L: L0 → L1 → … → Ln-1 → Ln,
  *reorder it to:
  *L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
  */
ListNode* Solution::reorderList(ListNode* A) {
    stack<ListNode*> mystack;
    ListNode *current=A,*fwd;
    ListNode *half=A;
    bool yes=1;
    while(current){
        current=current->next;
        if(yes){
            half=half->next;
            yes=0;
        }else yes=1;
    }
    while(half){
        mystack.push(half);
        half=half->next;
    }
    current=A;
    fwd=current->next;
    while(!mystack.empty()){
        half=mystack.top();
        current->next=half;
        half->next=fwd;
        current=fwd;
        fwd=fwd->next;
        mystack.pop();
    }
    current->next=NULL;
    return A;
}
