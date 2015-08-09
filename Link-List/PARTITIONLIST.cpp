/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/*
 *Given a linked list and a value x,
 *partition it such that all nodes less than x come before nodes greater than or equal to x.
 *You should preserve the original relative order of the nodes in each of the two partitions.
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *current=A;
    ListNode *previous=NULL;
    ListNode *head=NULL;
    ListNode *tail=NULL;
    while(current){
        if(current->val < B){
            if(previous)
                previous->next=current->next;
            else A=current->next;
            if(!head){
                head=current;
                tail=current;
            }else {
                tail->next=current;
                tail=current;
            }
            current->next=NULL;
            if(previous)
                current=previous->next;
            else current=A;
        }
        else{
            previous=current;
            current=current->next;
        }
    }
    if(tail)
        tail->next=A;
    else head=A;
    return head;
    }
