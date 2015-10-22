/*
 *Equilibrium index of an array is an index such that 
 *sum of elements at lower indexes is equal to the sum of elements at higher indexes
 *write function to implement it
 *Time=O(n) & space O(1)
 */
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
#define OUT(a) printf("%d\n",a);
using namespace std;
int *array;
/* returns equlibrium index if not present returns -1 */
int equlibrium(int n){
	int i;	//loop variable
	int rightsum,leftsum,total=0;
	FOR(i,n)
		total+=array[i];
	leftsum=array[0];
	LOOP(i,1,n-1){
		rightsum=total-leftsum-array[i];
		if(rightsum==leftsum)
			return i;
		leftsum+=array[i];
	}
	return -1;
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	IN(n);
	array=new int[n];
	FOR(i,n)
		IN(array[i]);
	OUT(equlibrium(n));
}
