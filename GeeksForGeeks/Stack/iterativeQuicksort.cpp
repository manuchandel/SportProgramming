/*
 *Implement QuickSort algorithm iteratively.
 *Avg Time=O(nlogn)  & Avg space=O(logn)
 *
 */
#include <cstdio>
#include <stack>
#include <ctime>
#include <cstdlib>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
struct Index{
	int b,e;
	Index(int x,int y){
		b=x;
		e=y;
	}
};
Index set(int x,int y){
	return Index(x,y);
}
stack <Index> indexstack;
int swap(int& a,int& b){
	int temp=a;
	a=b;
	b=temp;
}
void iterativeQuickSort(int *array,int n){
	indexstack.push(set(0,n-1));	//push the problem on stack
	int pivot,l,r,end,start;
	while(!indexstack.empty()){		//process till all subproblems are solved
		start=indexstack.top().b;
		end=indexstack.top().e;
		pivot=start;	//startng element is taken as pivot
		l=start+1;
		r=end;
		while(l<=r){	//filter elements across pivot
			if(array[l]<=array[pivot])
				l++;
			else if(array[r]>array[pivot])
				r--;
			else swap(array[l],array[r]);
		}
		swap(array[pivot],array[l-1]);
		indexstack.pop();	//pop the current processed elements in the range start to end
		indexstack.push(set(l,end));	//push the second subproblem 
		indexstack.push(set(start,l-2));	//push the first subproblem
		/* pop the subproblems where beginning index is greater than end index */
		while(!indexstack.empty() && indexstack.top().b>=indexstack.top().e) indexstack.pop();
	}
}
int main(){
	srand(time(0));
	int i;	//loop variable
	int n;	//no of elements
	IN(n);
	int *array=new int[n];
	FOR(i,n)
		array[i]=rand()%1000;
	FOR(i,n)
		printf("%d ",array[i]);
	printf("\n");
	iterativeQuickSort(array,n);
	FOR(i,n)
		printf("%d ",array[i]);
	printf("\n");
	
}
