/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    if(!A)
        return 0;
    if(!(A->next))
        return 1;
    ListNode *hare=A;
    ListNode *tort=A;
    ListNode *B=NULL;
    while(hare){
        hare=hare->next;
        if(!hare){
            tort=tort->next;
            break;
        }
        hare=hare->next;
        B=tort;
        tort=tort->next;
    }
    if(B)
        B->next=NULL;
    B=tort;
    ListNode *C=NULL;
    ListNode *D=B;
    ListNode *E=B;
    while(D){
        E=D->next;
        D->next=C;
        C=D;
        D=E;
    }
    
    while(A || C){
        if(!A || !C)
            return 0;
        if(A->val!=C->val)
            return 0;
        A=A->next;
        C=C->next;
    }
    return 1;
}
