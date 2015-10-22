#include <stdio.h>
long long gcd(long long A,long long B){
	if(B==0)
		return A;
	return gcd(B,A%B);
}
long long modExp(long long a,long long b,long long c){
	long long ans=1;
	while(b>0){
		if(b&1){
			ans*=a;
			ans%=c;
		}
		a*=a;
		a%=c;
		b=b>>1;
	}
	return ans;
}
int main()
{
    int n,i;
    long long A[50];
    long long fx=1,gx=1,c=1000000007;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	scanf("%lld",&A[i]);
    	fx=fx*A[i];
    	fx%=c;
    }
    gx=A[0];
    i=1;
    while(gx!=1 && i<n){
    	gx=gcd(gx,A[i]);
    	i++;
    }
    printf("%lld\n",modExp(fx,gx,c));
}

