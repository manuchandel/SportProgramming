/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/*
 *Given a sorted linked list, delete all duplicates such that each element appear only once.
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *current=A;
    ListNode *fwd=A->next;
    while(fwd){
        if(current->val==fwd->val){
            current->next=fwd->next;
            fwd->next=NULL;
            free(fwd);
            fwd=current->next;
        }
        else{
            current=current->next;
            fwd=fwd->next;
        }
    }
    return A;
}
