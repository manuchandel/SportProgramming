/*
 *You are given a list of n-1 integers and these integers are in the range of 1 to n.
 *There are no duplicates in list.
 *One of the integers is missing in the list. Write an efficient code to find the missing integer
 *time=O(n) space=O(1) no extra space
 *uses bitwise xor
 */
#include <cstdio>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;

int function(int n){
	int a=0,b=1,m;
	int i;		//loop variable
	FOR(i,n-1){
		IN(m);
		a=a^m;          //xor of input elements
		b=b^(i+2);      //xor of elements 1 to n
	}
	return a^b;
}
int main(){
	int n;	// no of elements in given array
	int i;	// loop variable
	IN(n);
	printf("%d\n",function(n));
}
