/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/* Given a linked list, swap every two adjacent nodes and return its head */
ListNode* Solution::swapPairs(ListNode* A) {
  ListNode *previous=NULL,*pivot1=A,*pivot2=A->next;
  while(pivot2){
      pivot1->next=pivot2->next;
      pivot2->next=pivot1;
      if(previous)
        previous->next=pivot2;
      else A=pivot2;
      previous=pivot1;
      pivot1=pivot1->next;
      if(pivot1)
        pivot2=pivot1->next;
    else pivot2=NULL;
      
  }
  return A;
}
