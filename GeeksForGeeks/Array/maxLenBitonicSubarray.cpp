/*
 *Given an array A[0 … n-1] containing n positive integers, a subarray A[i … j] is bitonic 
 *if there is a k with i <= k <= j such that A[i] <= A[i + 1] ... <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j].
 *Write a function that takes an array as argument and returns the length of the maximum length bitonic subarray.
 *Expected time complexity of the solution is O(n)
 *Time =O(n)& extra space=O(1)
 */
#include <cstdio>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
int bitonic(int *array,int n){
	int i;	//loop variable
	int p=0,q=1;	//sequence pointers
	bool decreasing=0;	//marks whether sequence is decreasing
	int maxlength=0;
	int start=p,end=q-1;
	while(q<n){
		if(array[q]<array[q-1])
			decreasing=1;
		else if(array[q]>array[q-1]){
			if(decreasing){	// this condition tests the local minima point
				if(maxlength< q-p){
					maxlength=q-p;
					start=p;
					end=q-1;
				}
				p=q-1;
				/* condition necessary for egs like [7, 5, 4, 4, 4, 5, 6, 7, 8, 9] where local minimum is continous */
				while(p>0 && array[p]==array[p-1]) 
					p--;
				decreasing=0;
			}
		}
		q++;
	}
	if(maxlength<q-p){
		maxlength=q-p;
		start=p;
		end=q-1;
	}
	LOOP(i,start,end+1)
		printf("%d ",array[i]);
	printf("\n");
	return maxlength;
}
int main(){
	int i;	//loop variable
	int n;
	IN(n);
	int *array=new int [n];
	FOR(i,n)
		IN(array[i]);
	printf("%d\n",bitonic(array,n));
}
