/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* Merge Two Sorted Lists */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(!A)
        return B;
    if(!B)
        return A;
    ListNode *currentB=B;
    ListNode *currentA=A;
    ListNode *previousA;
    if(A->val > B->val){
        B=currentB->next;
        currentB->next=A;
        A=currentB;
        currentB=B;
        currentA=A;
    }
    while(currentA && currentB){
        if(currentA->val <= currentB->val){
            previousA=currentA;
            currentA=currentA->next;
        }else{
            previousA->next=B;
            B=currentB->next;
            currentB->next=currentA;
            previousA=currentB;
            currentB=B;
        }
    }
    if(!currentA)
        previousA->next=B;
    return A;
    
}
