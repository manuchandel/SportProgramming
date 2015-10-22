/*
 *Given an unsorted array of nonnegative integers, find a continous subarray which adds to a given number.
 *Time=O(n) & space =O(1)
 */
#include <cstdio>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
struct Index{
	int start;
	int end;
	Index (int a,int b){
		start=a;
		end=b;
	}
};
Index sum(int *array,int n,int x){
	int p=0,q=0;	//start and end pointers
	int currentsum=array[0];
	while(1){
		if(p>q){
			currentsum=array[p];
			q=p;
		}
		if(currentsum==x)
			return Index(p,q);
		else if(currentsum<x){
			q++;
			if(q==n)
				return Index(-1,-1);
			currentsum+=array[q];
		}else{	
			currentsum-=array[p];
			p++;
			if(p==n)
				return Index(-1,-1);
		}
	}
}
int main(){
	int i;	//loop variable
	int n;	//no of elements in array
	IN(n);
	int x;
	int *array=new int[n];
	FOR(i,n)
		IN(array[i]);
	IN(x);
	Index index=sum(array,n,x);
	printf("%d %d\n",index.start,index.end );	//if start and end index==-1 than sum do not exist


}
