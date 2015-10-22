/*
 *Write a program for mergesort
 *Time=O(nlog(n)) & space O(n)
 */
#include <cstdio>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
int *array;
void merge(int a,int mid,int b){
	int i=0;	//loop variable
	int temp[b-a+1];
	int ptra=a,ptrb=mid+1;
	while(ptra<=mid && ptrb<=b){
		if(array[ptra]<array[ptrb]){
			temp[i]=array[ptra];
			ptra++;
		}
		else {
			temp[i]=array[ptrb];
			ptrb++;
		}
		i++;
	}
	while(ptra<=mid){
		temp[i]=array[ptra];
		i++; ptra++;
	}
	while(ptrb<=b){
		temp[i]=array[ptrb];
		i++; ptrb++;
	}
	FOR(i,b-a+1)
		array[i+a]=temp[i];
}
void split(int a,int b){
	int mid=(a+b)>>1;
	if(a==b)
		return;
	split(a,mid);
	split(mid+1,b);
	merge(a,mid,b);

}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	IN(n);
	array=new int[n];
	FOR(i,n)
		IN(array[i]);
	split(0,n-1);
	FOR(i,n)
		printf("%d " ,array[i]);
	printf("\n");
}
