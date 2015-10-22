/*
 *Segregate 0s and 1s in an array
 *Time=O(n) & space O(1) & traverse array once
 */
#include <cstdio>
#include <algorithm>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
int *array;
void swap(int& a,int& b){
	int temp=a;
	a=b;
	b=temp;
}
/* move left pointers and right pointers swap if 1 at left 0 at right */
void function(int n){
	int left=0,right=n-1;
	while(left<right){
		if(array[left]==0)
			left++;
		else if(array[right]==1)
			right--;
		else swap(array[left],array[right]);
	}
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	IN(n);
	array=new int[n];
	FOR(i,n)
		IN(array[i]);
	function(n);
	FOR(i,n)
		printf("%d ",array[i]);
}
