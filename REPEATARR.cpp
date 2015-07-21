/*
 *Given a read only set of n + 1 integers between 1 and n.
 *find one number that repeats in linear time using less then O(n) space and traversing the stream sequentially O(1) times.
 *Time O(nlogn) & space O(sqrt(n))
 */

 /*
 *Split the numbers from 1 to n in sqrt(n) ranges so that range i corresponds to [sqrt(n) * i .. sqrt(n) * (i + 1)).
 *Do one pass through the stream of numbers and figure out how many numbers fall in each of the ranges.
 *At least one of the ranges will contain more than sqrt(n) elements.
 *Do another pass and process just those elements in the oversubscribed range.
 *Using a hash table to keep frequencies, you’ll find a repeated element.
 *This is O(sqrt(n)) memory and 2 sequential passes through the stream.
 */
#include <iostream>
#include <cmath>
#include <algorithm>
#define FOR(i,n) for(i=0;i<n;i++)
#define IN(x) cin>>x
#define OUT(x) cout<<x
using namespace std;
/* function which returns any of the repeating element */
int repeatingElement(int *A,int n){
	int i;	//loop variable
	int sq=sqrt(n);
	int range=n/sq;
	int arr[range+1];
	int blockno=range;	//set default block number to last block
	for(i=0;i<range+1;i++)
		arr[i]=0;
	for(i=0;i<n;i++)
		arr[A[i]/sq]+=1;
	i=1;
	while(i<range && arr[i]<=sq) i++;
	if(arr[0]==sq)	//for zeroth block totoal elements will be sq-1 as 0 is not part of input
		blockno=0;
	for(i=0;i<sq;i++)
		arr[i]=0;
	for(i=0;i<n;i++){
		if(A[i]>=blockno*sq && A[i]<(blockno+1)*sq){
			arr[A[i]-blockno*sq]+=1;
			if(arr[A[i]-blockno*sq]>1)
				return A[i];
		}

	}return -1;
}
int main(){
	int n;	//no of elements
	IN(n);	//input n
	int i;
	int *arr=new int[n];
	FOR(i,n)
		IN(arr[i]);
	OUT(repeatingElement(arr,n));OUT(endl);
	
}
