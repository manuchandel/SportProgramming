/*
 *Implement tower of hanoi
 *Time=O(2^n) & space =O(1)
 */
#include <cstdio>
#include <stack>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
void towerOfhanoi(int n,char frompole,char topole,char auxpole){
	if(n==1){
		printf("move 1 disk from pole %c to pole %c\n",frompole,topole);
		return;
	}
	towerOfhanoi(n-1,frompole,auxpole,topole);
	printf("move 1 disk from pole %c to pole %c\n",frompole,topole);
	towerOfhanoi(n-1,auxpole,topole,frompole);
}


int main(){
	int n;	//no of poles
	IN(n);
	towerOfhanoi(n,'A','C','B');
}
