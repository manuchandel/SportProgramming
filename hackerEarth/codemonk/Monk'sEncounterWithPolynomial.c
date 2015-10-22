#include <stdio.h>
int expression(long long A,long long B,long long C,long long K,long long x0){
	long long val=A*x0*x0;
	val+=(B*x0);
	val+=C;
	val-=K;
	if(val >= 0)
		return 1;
	return 0;
}
int main()
{
	int T;
	long long A,B,C,K,x0;
	long long l,r,mid;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&A,&B,&C,&K);
		l=0; r=100000;
		while(l<=r){
			mid=(l+r)>>1;
			if(expression(A,B,C,K,mid)){
				x0=mid;
				r=mid-1;
			}else l=mid+1;
		}
		printf("%lld\n",x0);
		
	}
    return 0;
}

