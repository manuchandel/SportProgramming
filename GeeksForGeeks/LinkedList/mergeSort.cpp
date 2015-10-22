/*
 *Implementation of merge sort on link list
 *Time=O(nlogn) & space O(1)
 */
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
#define OUT(a) printf("%d ",a)
#define LN printf("\n")
using namespace std;
struct list{
	int data;
	list *link;
};
void add(list** head,int x){
	list *newone=new list;
	newone->data=x;
	newone->link=*head;
	*head=newone;
	newone=NULL;
}
void merge(list **head1,list *head2){
	if(!head2)
		return;
	list *p=*head1,*q=head2;
	list *prev=p;
	if(p->data>q->data){
		*head1=head2;
		q=q->link;
		head2->link=p;
		prev=head2;
	}
	else p=p->link;
	while(p && q){
		if(p->data>q->data){
			prev->link=q;
			prev=q;
			q=q->link;
			prev->link=p;
		}else {
			prev=p;
			p = p->link;
		}
	}
	while(p){	//condition necessary for data 46 625 409
		prev=p;
		p=p->link;
	}
	prev->link=q;	//merging the remaining list
}
void split(list **head){
	if(!(*head)->link)
		return;
	list *hare,*turtle;
	turtle=*head;
	hare=(*head)->link;
	bool var=1;
	while(hare){
		if(var)
			hare=hare->link;
		else{
			hare=hare->link;
			turtle=turtle->link;
		}
		var=~var;
	}
	hare=turtle->link;
	turtle->link=NULL;
	split(head);
	split(&hare);
	merge(head,hare);
	

}
void print(list* head){
	list* current=head;
	int i;
	while(current){
		OUT(current->data);
		current=current->link;
	}
	LN;
}
int main(){
	srand(time(0));
	int i;	// loop variable
	int n;	// no of elements in list
	IN(n);
	list* head=NULL;
	FOR(i,n){
		add(&head,rand()%1000);
	}
	print(head);
	split(&head);
	print(head);

}
