/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    if(m==n)
        return A;
    ListNode *previous,*current,*front,*start=NULL,*end=NULL;
    previous=NULL;
    current=A;
    front=A->next;
    int i=1;
    while(front && i<n){
        if(i==m){
            start=current;
        }
        else if(i==m-1)
            end=current;
        previous=current;
        current=front;
        front=front->next;
        if(i>=m)
            current->next=previous;
        i++;
    }
    if(start)
        start->next=front;
    if(end)
        end->next=current;
    else A=current;
    return A;
    
}
