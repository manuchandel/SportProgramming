/*
 *find gcd of two numbers
 *Following implementation uses euclids algorithm
 *worst case time O(h) where h is no of digits in a and b
 */
#include <stdio.h>
#define IN(a) scanf("%d",&a)
using namespace std;
int gcd(int a,int b){
	int y=1;
	while(b>0){
		y=a%b;
		a=b;
		b=y;
	}
	return a;
}
int main(){
	int a,b;
	IN(a);
	IN(b);
	printf("%d\n",gcd(a,b));
}
