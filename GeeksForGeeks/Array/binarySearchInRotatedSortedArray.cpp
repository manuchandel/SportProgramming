/*
 *An element in a sorted array can be found in O(log n) time via binary search.
 *But suppose I rotate the sorted array at some pivot unknown to you beforehand
 *for instance, 1 2 3 4 5 might become 3 4 5 1 2.
 *Devise a way to find an element in the rotated array in O(log n) time.
 *Array do not contain duplicate entries
 *Time = O(logn) and space=O(1)
 */
#include <cstdio>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
int n;	// no of elements in given array
int *array;
int max(int a,int b){
	if(b>a)
		return b;
	return a;
}
/*pivot element is the biggest element in the array it will be bigger than both its neighbours*/
int pivotElement(int start,int end){
	int mid=start+(end-start)/2;
	if(mid==0||mid==n-1)
		return -1;
	if(start>end)
		return -1;
	if(array[mid]>array[mid-1]&&array[mid]>array[mid+1])
		return mid;
	else if(start==end)
		return -1;
	else return max(pivotElement(start,mid),pivotElement(mid+1,end));
}
/* searches element in array in logarithmic time*/
int binarySearch(int pivot,int x){
	int start=0,end=pivot;
	int mid;
	int i;	//loop variable
	/* 
	 *search will be carried out in two arrays one-half including pivot other excluding it
	 *on either side of pivot element elements are in the ascending order
	 */
	FOR(i,2){
		while(start<=end){
			mid=(start+end)>>1;
			if(array[mid]==x)
				return mid;
			else if(array[mid]<x)
				start=mid+1;
			else end=mid-1;
		}
		start=pivot+1;
		end=n-1;
	}
	return -1;
}
int main(){
	int i;	// loop variable
	IN(n);
	array=new int[n];
	FOR(i,n)
		IN(array[i]);
	int x;	// value to search for
	int pivot=pivotElement(0,n-1);
	IN(x);
	printf("%d\n",binarySearch(pivot,x));
}
