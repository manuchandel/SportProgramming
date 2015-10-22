/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /* return a pointer where list cycle begins else return NULL */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode *hare=A;
    ListNode *tortoise=A;
    do{
        hare=hare->next;
            if(!hare)
                return NULL;
        hare=hare->next;
        tortoise=tortoise->next;
    }
    while(hare && hare!=tortoise);
    if(!hare)
        return NULL;
    int n=0;
    do{
        hare=hare->next;
        n++;
    }while(tortoise!=hare);
    hare=A;
    tortoise=A;
    while(n--)
        hare=hare->next;
    while(hare!=tortoise){
        hare=hare->next;
        tortoise=tortoise->next;
    }
    return hare;
    
}
