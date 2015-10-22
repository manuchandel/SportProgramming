/*
 *Write a C++ program that, given an array A[] of n numbers and another number x,
 *determines whether or not there exist two elements in S whose sum is exactly x.
 *time=O(nlogn) if array is not sorted else O(n)
 */
#include <cstdio>
#include <algorithm>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
bool function(int *array,int n,int x){
	sort(array,array+n);
	int i;			//loop variable
	int begin=0,end=n-1; //begginning and end pointers
	while(end>begin){
		if(array[begin]+array[end]==x)
			return true;
		else if(array[begin]+array[end]>x)
			end--;		//move end pointer backwards
		else begin++;	//move begin pointer forward
	}
	return false;
}
int main(){
	int n;	// no of elements in given array
	int i;	// loop variable
	IN(n);
	int *array=new int[n];
	FOR(i,n)
		IN(array[i]);
	int x;	//sum to find
	IN(x);
	if(function(array,n,x))
		printf("SUM EXIST\n");
	else printf("SUM DOESNT EXIST\n");

}
