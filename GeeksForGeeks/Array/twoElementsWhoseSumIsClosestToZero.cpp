/*
 *An Array of integers is given, both +ve and -ve.
 *You need to find the two elements such that their sum is closest to zero
 *Time=O(nlog(n)) & space O(1)
 */
#include <cstdio>
#include <algorithm>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
int *array;
/* returns value which is closest to zero */
int zeroMin(int a,int b){
	int c=a,d=b;
	if(c<0)
		c*=-1;
	if(d<0)
		d*=-1;
	if(d<c)
		return b;
	return a;
}
int function(int n){
	sort(array,array+n);
	int l=0,r=n-1;
	int min=array[l]+array[r];
	int prev=min;
	int a=l,b=r;
	while(l<r){
		min=zeroMin(array[l]+array[r],min);
		if(prev!=min){
			a=l; b=r;
			prev=min;
		}
		if(array[l]+array[r]>0)
			r--;
		else l++;
	}
	printf("%d %d ",array[a],array[b]);
	return min;
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	IN(n);
	array=new int[n];
	FOR(i,n)
		IN(array[i]);
	printf("%d\n",function(n));
}
