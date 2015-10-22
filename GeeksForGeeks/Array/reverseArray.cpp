/*
 *Write a program to reverse an array
 *Time=O(n) space O(1)
 */
#include <cstdio>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void reverse(int *array,int n){
	int i;	//loop variable
	FOR(i,n/2)
		swap(array[i],array[n-1-i]);
}
int main(){
	int i;	// loop variable
	int n;// no of elements in given array
	IN(n);
	int *array=new int[n];
	FOR(i,n)
		IN(array[i]);
	reverse(array,n);
	FOR(i,n)
		printf("%d ",array[i]);
	printf("\n");
}
