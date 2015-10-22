/*
 *Write an efficient C++ program to find the sum of contiguous subarray,
 *within a one-dimensional array of numbers which has the largest sum
 *time=O(n) space=O(1) no additional space
 *uses kadane's algorithm returns 0 if all elements are negative
 */
#include <cstdio>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;

int function(int *array,int n){
	int i;	//loop variable
	int max_ending_here=0;
	int max_so_far=0;
	FOR(i,n){
		max_ending_here+=array[i];
		if(max_ending_here<0)
			max_ending_here=0;
		else if(max_so_far<max_ending_here)
			max_so_far=max_ending_here;
	}
	return max_so_far;
}
int main(){
	int n;	// no of elements in given array
	int i;	// loop variable
	IN(n);
	int *array=new int[n];
	FOR(i,n)
		IN(array[i]);
	printf("%d\n",function(array,n));
}
