/*
 *Given an unsorted array of n integers which can contain integers from 1 to n.
 *Some elements can be repeated multiple times and some other elements can be absent from the array.
 *Count frequency of all elements that are present and print the missing elements.
 *Avg Time=O(n) & space O(1)
 */
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
int *array;
void frequency(int n){
	int i=0;
	int ei;	//element index
	while(i<n){
		if(array[i]>0){
			ei=array[i]-1;
			if(array[ei]>0){
				array[i]=array[ei];
				array[ei]=-1;
			}
			else {
				array[ei]+=-1;
				i++;
			}
		}else i++;
	}
	FOR(i,n){
		if(array[i]>0)
			array[i]=0;
		else array[i]*=-1;
	}
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	IN(n);
	array=new int[n];
	FOR(i,n)
		IN(array[i]);
	frequency(n);
	FOR(i,n)
		printf("%d ",array[i]);
	printf("\n");
}
