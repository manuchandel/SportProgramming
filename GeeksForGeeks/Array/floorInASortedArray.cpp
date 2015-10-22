/*
 *Returns floor of a element in a sorted array
 *floor(x) <= x
 *Time=O(logn) & space O(1)
 *input is taken until eof is encountered or ctrl+D in linux
 */
#include <cstdio>
#include <algorithm>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
int *array;
/* returns index of floor of the element if floor present else returns -1 */
int floor(int n,int x){
	int l=0,r=n-1;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(array[mid]==x){
			if(mid!=0 && array[mid-1]==x)
				r=mid-1;
			else return mid;
		}
		else if(array[mid]<x)
			l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	int x; //element to find
	IN(n);
	array=new int[n];
	FOR(i,n)
		IN(array[i]);
	while(IN(x)!=EOF)
		printf("%d\n",floor(n,x));
}
