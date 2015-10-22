/*
 *Given an array of positive integers.
 *All numbers occur even number of times except one number which occurs odd number of times.
 *Find the number in O(n) time & constant space.
 *uses bitwise xor property a xor a=0 and 0 xor a=a
 */
#include <cstdio>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;

int function(int *array,int n){
	int i;	//loop variable
	int ans=0;
	FOR(i,n)
		ans=ans^array[i];	//bitwise xor of all elements
	return ans;
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
