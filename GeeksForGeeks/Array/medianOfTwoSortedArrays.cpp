/*
 *There are 2 sorted arrays A and B of size n and m each.
 *Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length n+m).
 *The complexity should be O(log(n+m))
 *Time =O(n) and space =O(1) 
 *In case of even number of elements it returns bigger median
 */
#include <cstdio>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
int n,m;// no of elements in given array
int *array1,*array2;
int min(int a,int b){
	if(b<a)
		return b;
	return a;
}
int max(int a,int b){
	if(b>a)
		return b;
	return a;
}
/* finds median in array*/
int median(){
	int start,end,mid;
	int medianIndex=(n+m)>>1;
	int nbour;
	start=max(0,medianIndex-m);	//optimizing start
	end=min(n-1,medianIndex);	//its worthless to look for elements withindex greater than medianIndex
	while(start<=end){
		mid=(start+end)>>1;
		nbour=medianIndex-mid;
		if(array1[mid]<=array2[nbour]){
			if(nbour==0||(nbour>0 && array1[mid]>=array2[nbour-1]))
				return array1[mid];
			else start=mid+1;
		}
		else end=mid-1;
	}
	start=max(0,medianIndex-n);	//optimizing start
	end=min(m-1,medianIndex);	//its worthless to look for elements withindex greater than medianIndex
	while(start<=end){
		mid=(start+end)>>1;
		nbour=medianIndex-mid;
		if(array2[mid]<=array1[nbour]){
			if(nbour==0||(nbour>0 && array2[mid]>=array1[nbour-1]))
				return array2[mid];
			else start=mid+1;
		}
		else end=mid-1;
	}
	return 0;
}
int main(){
	int i;	// loop variable
	IN(n);
	array1=new int[n];
	FOR(i,n)
		IN(array1[i]);
	IN(m);
	array2=new int[m];
	FOR(i,m)
		IN(array2[i]);
	printf("%d\n",median());
}
