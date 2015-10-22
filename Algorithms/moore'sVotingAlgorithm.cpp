/*
 *Majority Element: A majority element in an array A[] of size n is an element that appears more than n/2 times 
 *and hence there is at most one such element.
 *This implementation uses moores voting algorithm
 *time=O(n) space=O(1) no extra space
 */
#include <cstdio>
#include <algorithm>
#include <limits.h>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;

int function(int *array,int n){
	int count=0;
	int i;		//loop variable
	int maj_element=array[0];
	FOR(i,n){
		if(count==0)
			maj_element=array[i];
		if(array[i]==maj_element)
			count++;
		else count--;
	}
	count=0;
	FOR(i,n){	//second pass to check the maj element
		if(array[i]==maj_element)
			count++;
	}
	n=(n>>1)+1;
	if(count>=n)
		return maj_element;
	else return INT_MIN;		//if no majority element present return -infi
}
int main(){
	int n;	// no of elements in given array
	int i;	// loop variable
	IN(n);
	int *array=new int[n];
	FOR(i,n)
		IN(array[i]);
	int ans=function(array,n);
	if(ans!=INT_MIN)
		printf("%d\n",ans);
	else printf("NO MAJORITY ELEMENT EXIST\n");

}
