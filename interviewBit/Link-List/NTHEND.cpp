/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/* Given a linked list, remove the nth node from the end of list and return its head. */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode *current=A;
    int n=0;
    ListNode *previous=NULL;
    while(current){
        current=current->next;
        n++;
    }
    current=A;
    if(n <= B){
        A=A->next;
        free(current);
        return A;
    }
    n=n-B-1;
    while(n--){
        current=current->next;
    }
    previous=current;
    current=current->next;
    previous->next=current->next;
    current->next=NULL;
    free(current);
    return A;
    
}
