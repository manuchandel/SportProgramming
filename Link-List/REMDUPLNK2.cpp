/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
 *Given a sorted linked list, delete all nodes that have duplicate numbers
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *previous=NULL;
    ListNode *current=A;
    ListNode *fwd=A->next;
    bool ettu=0;
    while(fwd){
       if(current->val==fwd->val){
           current->next=fwd->next;
           fwd->next=NULL;
           free(fwd);
           fwd=current->next;
           ettu=1;
       }
       else if(ettu){
           if(previous)
            previous->next=current->next;
            else A=current->next;
           current->next=NULL;
           free(current);
           current=fwd;
           fwd=fwd->next;
           ettu=0;
       }
       else{
           previous=current;
           current=fwd;
           fwd=fwd->next;
       }
    }
    if(ettu){
        if(previous)
            previous->next=NULL;
        else A=NULL;
        free(current);
    }
    
   
    return A;
}

