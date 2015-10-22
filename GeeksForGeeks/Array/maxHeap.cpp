/*
 *Implementation of max heap
 *add() : Time=O(log(heapsize) & space O(1)
 *maxheapifybottom() & maxHeapify() : Time=O(log(heapsize) & space O(1)
 *buildheap() : Time=O(heapsize) & space O(1)
 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
#define OUT(a) printf("%d ",a)
#define LN printf("\n")
using namespace std;
vector <int> heap;
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
/* This function maintains heap property from i to top*/
void maxheapifybottom(int i,int n){
	if(i==0)
		return;
	int parent;
	if(i&1)	//if i is leftchild
		parent=(i-1)>>1;
	else parent=(i-2)>>1;	// i is right child
	if(heap[i]>heap[parent]){	//swap with parent
		swap(heap[i],heap[parent]);
		maxheapifybottom(parent,n);
	}
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
int deleteNode(int i){
	int pop=heap[i];
	heap[i]=heap[heap.size()-1];
	heap.pop_back();
	maxheapify(i,heap.size());
	return pop;
}
/* function builds max heap from input heap */
void buildHeap(){
	int i=heap.size()>>1;	//loop variable
	while(i>=0){
		maxheapify(i,heap.size());
		i--;
	}
}
/* function adds element to heap */
void add(int x){
	heap.push_back(x);
	maxheapifybottom(heap.size()-1,heap.size());
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given heap
	IN(n);
	int x;
	/* sample operations */
	FOR(i,n){
		IN(x);
		heap.push_back(x);
	}
	buildHeap();
	FOR(i,n)
		OUT(heap[i]);
	LN;
	add(100);
	FOR(i,heap.size())
		OUT(heap[i]);
	LN;
}
