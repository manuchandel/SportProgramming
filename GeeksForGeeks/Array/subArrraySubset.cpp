/*
 *Given two arrays: arr1[0..m-1] and arr2[0..n-1].
 *Find whether arr2[] is a subset of arr1[] or not. Both the arrays are not in sorted order.
 *Time=O(nlogn+mlogm) &space =O(1)
 */
#include <cstdio>
#include <algorithm>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
int bsearch(int *array,int n,int x){
	int l=0,r=n-1,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(array[mid]==x)
			return mid;
		else if(array[mid]>x)
			r=mid-1;
		else l=mid+1;
	}
	return -1;
}
bool isSubset(int *a,int n,int *b,int m){
	int i,j;	//loop variable
	sort(a,a+n);	//larger array
	sort(b,b+m);	//smaller array
	int start=bsearch(a,n,b[0]),
		end=bsearch(a,n,b[m-1]);
	if(start<0 || end<0)
		return false;
	i=start; j=0;
	while(i<=end){
		if(a[i]==b[j]){
			i++;j++;
		}else i++;
	}
	if(j==m)
		return true;
	return false;

	
}
int main(){
	int i;	// loop variable
	int n,m;	// no of elements in given array
	IN(n);
	int *a=new int[n];
	FOR(i,n)
		IN(a[i]);
	IN(m);
	int *b=new int[m];
	FOR(i,m)
		IN(b[i]);
	if(isSubset(a,n,b,m))
		printf("Array 2 is subset of Array 1\n");
	else printf("Array 2 is not subset of Array 1\n");
}
