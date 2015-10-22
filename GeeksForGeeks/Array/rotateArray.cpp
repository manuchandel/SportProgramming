/*
 *Write a program to rotate an array by d elements
 *In this implementation we rotate counter-clockwise and use juggling algo
 *Time=O(n) space O(1)
 */
#include <cstdio>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
/* uses euclids algorithm to find gcd */
int gcd(int a,int b){
	int y=1;
	while(y>0){
		y=a%b; a=b; b=y;
	}
	return a;
}
void rotate(int *array,int n,int d){
	int i,j;	//loop variable
	int set=gcd(n,d);		//gives number of sets
	int iterations=n/set;	//gives no of elements in a set
	int temp;
	FOR(i,set){			//for each set
		temp=array[i];
		FOR(j,iterations-1)
			array[(i+j*d)%n]=array[(i+j*d+d)%n];	//swap elements
		array[(i+(iterations-1)*d)%n]=temp;
	}
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	int d;	// number of elements to rotate by
	IN(n);
	int *array=new int[n];
	FOR(i,n)
		IN(array[i]);
	IN(d);
	rotate(array,n,d);
	FOR(i,n)
		printf("%d ",array[i]);
	printf("\n");
}
