/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/*Given a list, rotate the list to the right by k places, where k is non-negative.*/
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int n=1;
    ListNode *tail=A;
    ListNode *current=A;
    while(tail->next){
        n++;
        tail=tail->next;
    }
    if(B>=n)
        B%=n;
    if(B==0)
        return A;
    n=n-B-1;
    while(n--)
        current=current->next;
    tail->next=A;
    A=current->next;
    current->next=NULL;
    return A;
}

