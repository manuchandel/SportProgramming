#include <stdio.h>
#define FOR(i,n) for(i=0;i<n;i++)
int ispossible(int A[],int n,int val,int k){
	int i;
	int monks=0;
	int prevmonk=-val;
	FOR(i,n){
		if(prevmonk+val < A[i]){
			prevmonk=A[i]+val;
			monks++;
		}
	}
	if(monks<=k)
		return 1;
	return 0;
}
int comp(void *A,void *B){
	return (*(int*)A-*(int*)B);
}
int main()
{
    int n,k,i,l,r,mid,val;
    int A[100000];
    scanf("%d%d",&n,&k);
    FOR(i,n)
    	scanf("%d",&A[i]);
    qsort(A,n,sizeof(int),comp);
    l=0;r=10000000;val=-1;
    while(l<=r){
    	mid=(l+r)>>1;
    	if(ispossible(A,n,mid,k)){
    		val=mid;
    		r=mid-1;
    	}else l=mid+1;
    }
    printf("%d\n",val);
}

