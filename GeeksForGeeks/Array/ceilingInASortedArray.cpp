/*
 *Returns ceiling of a element in a sorted array
 *ceiling(x) > x and index(x) is smallest
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
int ceiling(int n,int x){
	int l=0,r=n-1;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(array[mid]<=x)
			l=mid+1;
		else r=mid-1;
	}
	if(r==n-1)
		return -1;
	return r+1;
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
		printf("%d\n",ceiling(n,x));
}
