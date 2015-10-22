/*
 *Inversion Count for an array indicates how far (or close) the array is from being sorted.
 *If array is already sorted then inversion count is 0.
 *If array is sorted in reverse order that inversion count is the maximum. 
 *Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
 *Time=O(nlog(n)) & space O(n)
 *If original array is needed than enhanceMerge should be called on its copy
 */
#include <cstdio>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
int *array;
/* sorts two arrays and counts inversions */
int merge(int a,int mid,int b){
	int i=0;	//loop variable
	int temp[b-a+1];
	int ptra=a,ptrb=mid+1;
	int inv=0;
	while(ptra<=mid && ptrb<=b){
		if(array[ptra]<=array[ptrb]){
			temp[i]=array[ptra];
			ptra++;
		}
		else {
			temp[i]=array[ptrb];
			/* if element of second array comes first than i elements of first array than inversions is i */
			inv+=mid-ptra+1;
			ptrb++;
		}
		i++;
	}
	while(ptra<=mid){
		temp[i]=array[ptra];
		i++; ptra++;
	}
	while(ptrb<=b){
		temp[i]=array[ptrb];
		i++; ptrb++;
	}
	FOR(i,b-a+1)
		array[i+a]=temp[i];
	return inv;
}
int enhanceMerge(int a,int b){
	int mid=(a+b)>>1;
	if(a==b)
		return 0;
	return enhanceMerge(a,mid)+enhanceMerge(mid+1,b)+merge(a,mid,b);
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	IN(n);
	array=new int[n];
	FOR(i,n)
		IN(array[i]);
	printf("%d\n",enhanceMerge(0,n-1));
}
