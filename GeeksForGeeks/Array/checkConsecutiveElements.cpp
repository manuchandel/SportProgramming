/*
 *Given an unsorted array of numbers, write a function that returns true if array consists of consecutive numbers.
 *Time=O(n) & space O(n)
 */
#include <cstdio>
#include <stack>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
stack <int> mystack;
bool check(int *array,int n){
	int i;	//loop variable
	int max=array[0],min=array[0];
	FOR(i,n){
		if(max<array[i])
			max=array[i];
		else if(min>array[i])
			min=array[i];
	}
	if(max-min+1!=n)
		return false;
	bool visited[n];	//All elements should be distinct
	FOR(i,n)
		visited[i]=0;
	FOR(i,n)
		visited[array[i]-min]=1;
	FOR(i,n)
		if(!visited[i])
			return false;
	return true;

}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	IN(n);
	int *array=new int[n];
	FOR(i,n)
		IN(array[i]);
	if(check(array,n))
		printf("All elements are consecutive\n");
	else printf("All elements are not consecutive\n");

}
