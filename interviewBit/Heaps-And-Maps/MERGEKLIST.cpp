/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct Box{
    int val;
    int k;
    Box(int a,int b){
        val=a;
        k=b;
    }
};
bool compare(Box b1,Box b2){
    if(b1.val>b2.val)
        return true;
    return false;
}
void add(int a,ListNode **tail){
    ListNode *listnode=new ListNode(a);
    if(!(*tail)){
        (*tail)=listnode;
        return;
    }
    (*tail)->next=listnode;
    (*tail)=listnode;
}
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    int i;
    int K=A.size();
    vector<Box> v;
    Box box(0,0);
    ListNode *current[K];
    ListNode *previous[K];
    for(i=0;i<K;i++){
        current[i]=A[i];
        if(current){
            box.val=current[i]->val;
            box.k=i;
            v.push_back(box);
        }
        previous[i]=0;
    }
    make_heap(v.begin(),v.end(),compare);
    ListNode *head=NULL;
    ListNode *tail=NULL;
    while(!v.empty()){
        int top=v.front().val;
        i=v.front().k;
        if(current[i]){
            previous[i]=current[i];
            current[i]=current[i]->next;
            previous[i]->next=NULL;
            delete(previous[i]);
        }
        pop_heap(v.begin(),v.end(),compare);
        v.pop_back();
        if(current[i]){
            box.val=current[i]->val;
            box.k=i;
            v.push_back(box);
            push_heap(v.begin(),v.end(),compare);
        }
        if(!tail){
            add(top,&tail);
            head=tail;
        }else add(top,&tail);
    }
    return head;
}
