/*
 *Write a program to print all the LEADERS in the array.
 *An element is leader if it is greater than all the elements to its right side.
 *And the rightmost element is always a leader.
 *For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.
 *Time=O(n) & space O(1)
 */
#include <cstdio>
#define IN(a) scanf("%d",&a)
#define FOR(a,b,c) for(a=c;a<b;a++)
using namespace std;
void Leader(int *array,int n){
	int i=n-1;	//loop variable
	int max=array[n-1];
	printf("%d",max);
	while(i>=0){
		if(max<array[i]){
			max=array[i];
			printf(" %d",max);
		}
		i--;
	}
	printf("\n");
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	IN(n);
	int *array=new int[n];
	FOR(i,n,0)
		IN(array[i]);
	Leader(array,n);
}
