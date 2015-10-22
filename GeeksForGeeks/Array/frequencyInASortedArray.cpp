/*
 *Find frequency of a element in a sorted array
 *Time=O(logn) & space O(1)
 *input is taken until eof is encountered or ctrl+D in linux
 */
#include <cstdio>
#include <algorithm>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
int *array;
/* returns frequency of a number in sorted array */
int freq(int n,int x){
	int l=0,r=n-1,left=0,right=-1;
	int mid;
	/* finds left most i such that x==array[i] */
	while(l<=r){
		mid=(l+r)>>1;
		if(array[mid]==x){
			left=mid;
			r=mid-1;
		}
		else if(array[mid]<x)
			l=mid+1;
		else r=mid-1;
	}
	l=0,r=n-1;
	/* finds right most i such that x==array[i] */
	while(l<=r){
		mid=(l+r)>>1;
		if(array[mid]==x){
			right=mid;
			l=mid+1;
		}
		else if(array[mid]<x)
			l=mid+1;
		else r=mid-1;
	}
	return right-left+1;
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	int x; //element to find frequency
	IN(n);
	array=new int[n];
	FOR(i,n)
		IN(array[i]);
	while(IN(x)!=EOF)
		printf("%d\n",freq(n,x));
}
