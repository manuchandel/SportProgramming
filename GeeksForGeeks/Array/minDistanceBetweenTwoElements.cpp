/*
 *Given an unsorted array arr[] and two numbers x and y, find the minimum distance between x and y in arr[].
 *The array might also contain duplicates.
 *You may assume that both x and y are different and present in arr[]
 *Time=O(n) &space =O(1)
 *1) Traverse array from left side and stop if either x or y are found. Store index of this first occurrrence in a variable say prev
 *2) Now traverse arr[] after the index prev.
 *If the element at current index i matches with either x or y then check if it is different from arr[prev].
 *If it is different then update the minimum distance if needed. If it is same then update prev i.e., make prev = i.
 *Input: arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, x = 3, y = 6
 *Output: Minimum distance between 3 and 6 is 4.
 *Input: arr[] = {2, 5, 3, 5, 4, 4, 2, 3}, x = 3, y = 2
 *Output: Minimum distance between 3 and 2 is 1.
 */
#include <cstdio>
#include <algorithm>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
int min(int a,int b){
	return b<a?b:a;
}
int distance(int *array,int n,int x,int y){
	int i=0;	//loop variable
	int prev,dist=n;
	while(array[i]!=x && array[i]!=y) i++;
	prev=i;
	LOOP(i,prev+1,n)
		if(array[i]==x || array[i]==y){
			if(array[i]!=array[prev])
				dist=min(dist,i-prev);
			prev=i;
		}
	return dist;
}


int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	IN(n);
	int *array=new int[n];
	FOR(i,n)
		IN(array[i]);
	int x,y;	//distance to find between these numbers
	IN(x); IN(y);
	printf("%d\n",distance(array,n,x,y));
	
}
