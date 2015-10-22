/*
 *Implement Quick Sort
 *Avg Time=O(nlogn) & space O(1)
 *This implementation assumes pivot as first element
 */
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
int *array;
void swap(int& a,int& b){
	int temp=a;
	a=b;
	b=temp;
}
void quicksort(int start,int end){
	if(start>=end)
		return;
	int pivot=array[start];
	int l=start+1,r=end;
	int i;
	while(l<=r){
		if(array[l]<=pivot)
			l++;
		else if(array[r]>pivot)
			r--;
		else swap(array[l],array[r]);
	}
	swap(array[start],array[l-1]);
	quicksort(start,l-2);
	quicksort(l,end);

}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	IN(n);
	array=new int[n];
	FOR(i,n)
		IN(array[i]);
	quicksort(0,n-1);
	FOR(i,n)
		printf("%d ",array[i]);
	printf("\n");
}
