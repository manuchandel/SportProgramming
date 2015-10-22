/*
 *Given an array of positive numbers,
 *find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array.
 *So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).
 *Answer the question in most efficient way.
 *Time=O(n) space O(1)
 *let sum(0,i)= maxsum from 0 to i
 *sum(0,i)=max(sum(0,i-2)+array[i],sum(0,i-1))
 */
#include <cstdio>
#define IN(a) scanf("%d",&a)
#define FOR(a,b,c) for(a=c;a<b;a++)
using namespace std;
/* returns maximum of two numbers */
int max(int a,int b){
	if(b>a)
		return b;
	return a;
}
int maxSum(int *array,int n){
	int i;	//loop variable
	int a=array[0],b=max(array[0],array[1]),c;
	FOR(i,n,2){
		c=b;
		b=max(array[i]+a,b);	
		b=max(b,array[i]);	//if array contains negative element than array[i] is also to be considered
		a=c;
	}
	return b;
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	IN(n);
	int *array=new int[n];
	FOR(i,n,0)
		IN(array[i]);
	printf("%d\n",maxSum(array,n));
}
