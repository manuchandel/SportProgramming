/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/* Sort a linked list using insertion sort. */
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode *sorted=A;
    ListNode *current=sorted->next;
    ListNode *currentSorted,*prevsorted;
    while(sorted->next){
        current=sorted->next;
        if(current->val >= sorted->val){
            sorted=current;
            current=current->next;
        }
        else {    
            sorted->next=current->next;
            current->next=NULL;
            currentSorted=A;
            prevsorted=NULL;
            while(currentSorted!=sorted){
                if(currentSorted->val <= current->val){
                    prevsorted=currentSorted;
                    currentSorted=currentSorted->next;
                }else{
                    if(prevsorted)
                        prevsorted->next=current;
                    else A=current;
                    current->next=currentSorted;
                    break;
                }
            }
            if(currentSorted==sorted){
                if(sorted->val <= current->val){
                    current->next=sorted->next;
                    sorted->next=current;
                    sorted=current;
                }else{
                    if(prevsorted){
                        prevsorted->next=current;
                    }else A=current;
                    current->next=sorted;
                }
            }
        }
    }
    return A;
}
