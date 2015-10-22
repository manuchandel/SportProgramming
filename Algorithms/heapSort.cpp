/*
 *Implementation of heap sort
 *Time=O(nlogn) & space O(1)
 *maxHeapify() : Time=O(logn) & space O(1)
 *buildheap() : Time=O(n) & space O(1)
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
int *heap;
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
/* This function maintains heap property from i to bottom*/
void maxheapify(int i,int n){
	int lc=(i<<1)+1,rc=(i<<1)+2;
	if(lc>=n)	//return from root level
		return;
	if(rc<n){	//if right child exist
		if(heap[i]>=heap[lc] && heap[i]>=heap[rc]) //no swap required
			return;
		else if(heap[lc]>=heap[rc]){	//swap element at i with left child
			swap(heap[i],heap[lc]);
			maxheapify(lc,n);
		}else{
			swap(heap[i],heap[rc]);	//swap element at i with right child
			maxheapify(rc,n);
		}
	}
	else{	//no right child exist this is second lat level
		if(heap[i]<heap[lc])	//swap with left child
			swap(heap[i],heap[lc]);
	}
}
/* deletes node at position i */
int deleteNode(int i,int n){
	int pop=heap[i];
	swap(heap[i],heap[n-1]);
	maxheapify(i,n-1);
	return pop;
}
/* function builds max heap from input heap */
void buildHeap(int n){
	int i=n>>1;	//loop variable
	while(i>=0){
		maxheapify(i,n);
		i--;
	}
}
/* this function implements heapsort */
void heapsort(int n){
	int i;
	buildHeap(n);
	FOR(i,n-1)
		deleteNode(0,n-i);
}
int main(){
	srand(time(0));
	int i;	// loop variable
	int n;	// no of elements in given heap
	IN(n);
	heap=new int[n];
	/* input array */
	FOR(i,n)
		heap[i]=rand()%1000;
	FOR(i,n)
		OUT(heap[i]);
	LN;
	heapsort(n);
	FOR(i,n)
		OUT(heap[i]);
	LN;
}
