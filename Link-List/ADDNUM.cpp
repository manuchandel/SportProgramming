/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*
  *You are given two linked lists representing two non-negative numbers.
  *The digits are stored in reverse order and each of their nodes contain a single digit.
  *Add the two numbers and return it as a linked list.
  */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
   ListNode *currentA=A;
   ListNode *currentB=B;
   int sum=0,carry=0;
   if(!A)
    return B;
   if(!B)
    return A;
   while(currentA->next && currentB->next){
       sum=currentA->val+currentB->val+carry;
       carry=sum/10;
       currentA->val=sum%10;
       currentA=currentA->next;
       currentB=currentB->next;
   }
   sum=currentA->val+currentB->val+carry;
   carry=sum/10;
   currentA->val=sum%10;
   if(!(currentA->next))
       currentA->next=currentB->next;
    while(currentA->next){
        currentA=currentA->next;
        sum=currentA->val+carry;
       carry=sum/10;
       currentA->val=sum%10;
    }
    if(carry>0){
        ListNode *l=new ListNode(carry);
        currentA->next=l;
        l->next=NULL;
    }
    return A;
}
