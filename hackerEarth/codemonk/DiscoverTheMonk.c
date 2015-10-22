#include <stdio.h>
int present(int A[],int n,int K){
	int l=0,r=n-1,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(A[mid]==K)
			return 1;
		else if(A[mid]>K)
			r=mid-1;
		else l=mid+1;
	}
	return 0;
}
int comp(const void *A, const void *B){
	return (*(int*)A- *(int*)B);
}
int main()
{
    int N,Q,K,i;
    int A[100000];
    scanf("%d%d",&N,&Q);
    for(i=0;i<N;i++)
    	scanf("%d",&A[i]);
    qsort(A,N,sizeof(int),comp);
    printf("\n");
    while(Q--){
    	scanf("%d",&K);
    	if(present(A,N,K))
    		printf("YES\n");
    	else printf("NO\n");
    }
    return 0;
}

