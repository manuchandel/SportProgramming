#include <stdio.h>
#define MAX 100000
#define FOR(i,n) for(i=0;i<n;i++)
#define ll long long
#define IN(x) scanf("%lld",&x)
int max(int a,int b){
	if(a>b)
		return a;
	return b;
}
int monkiness(ll B[],ll k,int n){
	int m=-1;
	int l=0,r=n-1,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(k<=B[mid]){
			m=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return m;
}
int main()
{
	int i,T,n,m=0;
    ll A[MAX];
    ll B[MAX];
    scanf("%d",&T);
    while(T--){
    	m=0;
    	IN(n);
    	FOR(i,n)
    		IN(A[i]);
    	FOR(i,n)
    		IN(B[i]);
    	FOR(i,n)
    		m=max(m,monkiness(B,A[i],n)-i);	
    	printf("%d\n",m);    	
    }
}

