/*
 *Given an unsorted array arr[0..n-1] of size n,
 *find the minimum length subarray arr[s..e] such that 
 *sorting this subarray makes the whole array sorted
 *Time=O(n) & space O(1)
 */
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
int *array;
struct tupple{
	int a,b;
};
tupple subarray(int n){
	int i; //loop variable
	int p=0,q=n-1;
	/* finds first element from start which is bigger than its next element */
	while(array[p]<=array[p+1]&&p<n-2) p++;
	/* finds first element from end which is smaller than its left element */
	while(array[q]>=array[q-1]&&q>0) q--;
	
	int max=array[p],min=array[p];
	i=p;
	/* finds minimum and maximum in canidate array */
	while(i<=q){
		if(array[i]>max)
			max=array[i];
		else if(array[i]<min)
			min=array[i];
		i++;
	}
	i=0;
	/* includes left elements in candidate array */
	while(array[i]<min && i<p) i++;
	p=i;
	i=n-1;
	/* includes right elements in candidate array */
	while(array[i]>max && i>q) i--;
	q=i;
	tupple t;
	t.a=p;t.b=q;
	return t;
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	IN(n);
	array=new int[n];
	FOR(i,n)
		IN(array[i]);
	subarray(n);
	tupple t=subarray(n);
	printf("%d %d\n",t.a,t.b);
}
