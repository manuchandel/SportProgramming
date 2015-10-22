/*
 *Binary search in a sorted array
 *Time=O(logn) & space O(1)
 *input is taken until eof is encountered or ctrl+D in linux
 */
#include <cstdio>
#include <algorithm>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
int *array;
/* returns index of element if found else returns -1 */
int binarySearch(int n,int x){
	int l=0,r=n-1;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(array[mid]==x)
			return mid;
		else if(array[mid]<x)
			l=mid+1;
		else r=mid-1;
	}
	return -1;
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
		printf("%d\n",binarySearch(n,x));
}
