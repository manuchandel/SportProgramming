/*
 *Given an array of n positive integers.
 *Write a program to find the sum of maximum sum subsequence of the given array such that the integers in the subsequence are sorted in increasing order.
 *For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100), if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10)
 *if the input array is {10, 5, 4, 3}, then output should be 10
 *Time =O(n^2) & extra space=O(n)
 */
#include <cstdio>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
int max(int a,int b){
	if(b>a)
		return b;
	return a;
}
int maxSumSubsequence(int *array,int n){
	int i,j;	//loop variable
	int aux[n];	//auxilary array of size n
	int maxSum=array[0];
	FOR(i,n){
		aux[i]=array[i];
		FOR(j,i)
			if(array[j]<=array[i])
				aux[i]=max(aux[i],array[i]+aux[j]);
		maxSum=max(maxSum,aux[i]);
	}
	return maxSum;
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	IN(n);
	int *array=new int[n];
	FOR(i,n)
		IN(array[i]);
	printf("%d\n",maxSumSubsequence(array,n));
}
