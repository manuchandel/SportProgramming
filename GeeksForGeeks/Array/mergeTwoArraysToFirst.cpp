/*
 *There are two sorted arrays. First one is of size m+n containing only m elements.
 *remaining n-m elements are marked invalid we assume marked -1
 *Another one is of size n and contains n elements.
 *Merge these two arrays into the first array of size m+n such that the output is sorted.
 *eg 2 -1 7 -1 -1 10 -1 and 5 8 12 14 merges to 2 5 7 8 10 12 14
 *Time =O(n) and space =O(1) 
 */
#include <cstdio>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
int nplusm,m;// no of elements in given array
int *array1,*array2;
/* moves elements of array1 to end assuming -1 is invalid element*/
int moveElements(){
	int index,ptr;
	index=ptr=nplusm-1;
	while(ptr>=0){
		if(array1[ptr]!=-1){
			array1[index]=array1[ptr];
			index--;
		}
		ptr--;
	}
	index++;
	return index;
}
/* fuction which merges two arrays into one */
void function(){
	int ptr1,ptr2=0,index=0;
	ptr1=moveElements();
	while(ptr1<nplusm && ptr2<m){
		if(array1[ptr1]<=array2[ptr2]){
			array1[index]=array1[ptr1];
			ptr1++;
		}else {
			array1[index]=array2[ptr2];
			ptr2++;
		}
		index++;
	}
	while(ptr2<m){
		array1[index]=array2[ptr2];
		ptr2++;
		index++;
	}
}
int main(){
	int i;	// loop variable
	IN(nplusm);
	array1=new int[nplusm];
	FOR(i,nplusm)
		IN(array1[i]);
	IN(m);
	array2=new int[m];
	FOR(i,m)
		IN(array2[i]);
	function();
	FOR(i,nplusm)
		printf("%d ",array1[i] );
	printf("\n");
}
