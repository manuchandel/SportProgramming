/*
 *Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.
 *If such arrangement is not possible make no changes
 *Time O(nlogn) & space O(1)
 */
#include <iostream>
#include <algorithm>
#define FOR(i,n) for(i=0;i<n;i++)
#define IN(x) cin>>x
#define OUT(x) cout<<x
using namespace std;
/* utility function to swap two elements */
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
/*function to print next permutation.
 *start by finding pivot element.
 *pivot element is described as first element encountered from scanning array right to left such that it is smaller than next element
 */
void nextPermutation(int *arr,int n){
	int i;	//loop variable
	i=n-2;
	while(i>=0 && arr[i]>=arr[i+1]) i--;	//find pivot index
	if(i==-1)	//if no pivot index found return this is the maximum possible number
		return;
	int pivotIndex=i;
	int minIndex=pivotIndex+1;
	for(i=pivotIndex+1 ; i<n;i++){
		if(arr[i] <=arr[minIndex] && arr[i]> arr[pivotIndex])
			minIndex=i;
	}
	swap(arr[minIndex],arr[pivotIndex]);	//swap pivot index with minimum element greater than pivot to the right of pivot 
	sort(arr+pivotIndex+1,arr+n-1);	// sort the sequence to the right of the pivot
}
int main(){
	int n;	//no of elements
	IN(n);	//input n
	int i;
	int *arr=new int[n];
	FOR(i,n)
		IN(arr[i]);
	nextPermutation(arr,n);
	FOR(i,n-1)
		OUT(arr[i]<<" ");
	OUT(arr[n-1]);OUT(endl);
}
