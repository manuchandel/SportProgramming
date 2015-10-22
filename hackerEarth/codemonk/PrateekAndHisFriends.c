#include <stdio.h>
int canInvite(long long *A,long long x,int n){
	int p=0,q=0;
	while(q<n){
		if(A[q]-A[p]==x)
			return 1;
		else if(A[q]-A[p]>x) p++;
		else q++;
	}
	return 0;
}
int main()
{
	int i,n,T;
	long long x;
	long long *A=malloc(sizeof(long long)*1000001);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%lld",&x);
		A[0]=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&A[i]);
			A[i]+=A[i-1];			
		}
		if(canInvite(A,x,n+1))
			printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}

