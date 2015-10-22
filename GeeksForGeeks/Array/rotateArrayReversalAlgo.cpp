/*
 *Write a program to rotate an array by d elements
 *In this implementation we rotate counter-clockwise
 *Time=O(n) space O(1)
 */
#include <cstdio>
#define IN(a) scanf("%d",&a)
#define FOR(a,b,c) for(a=c;a<b;a++)
using namespace std;
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void reverse(int *array,int begin,int n){
	int i;	//loop variable
	FOR(i,(begin+n)/2,begin)
		swap(array[i],array[begin+n-1-i]);
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	int d;	// number of elements to rotate by
	IN(n);
	int *array=new int[n];
	FOR(i,n,0)
		IN(array[i]);
	IN(d);
	reverse(array,0,d);
	reverse(array,d,n);
	reverse(array,0,n);
	FOR(i,n,0)
		printf("%d ",array[i]);
	printf("\n");
}
