/*
 *Given a sorted array of n integers where each integer is in the range from 0 to m-1 and m > n.
 *Find the smallest number that is missing from the array.
 *Time=O(logn) & space O(1)
 *a)If arr[mid] greater than mid then the required element lies in left half.
 *b)Else the required element lies in right half.
 *All elements should be distinct
 *Input: {0, 1, 2, 6, 9}, n = 5, m = 10
 *Output: 3
 *Input: {4, 5, 10, 11}, n = 4, m = 12
 *Output: 0
 *Input: {0, 1, 2, 3}, n = 4, m = 5
 *Output: 4
 *Input: {0, 1, 2, 3, 4, 5, 6, 7, 10}, n = 9, m = 11
 *Output: 8
 */
#include <cstdio>
#include <stack>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
int missingElement(int *array,int n){
	int i;	//loop variable
	int mid,left=0,right=n-1;
	while(left<=right){
		mid=(left+right)>>1;
		if(array[mid]>mid)
			right=mid-1;
		else left=mid+1;
	}
	return left;
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	IN(n);
	int *array=new int[n];
	FOR(i,n)
		IN(array[i]);
	printf("%d\n",missingElement(array,n));
}
