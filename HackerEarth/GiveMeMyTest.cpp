#include <bits/stdc++.h>
#define IN(L) scanf("%d",&L)
#define mod 1000000007
using namespace std;
long long D[101];
long long fact[101];

long long x,y;
long long inv(long long a,long long b){
	if(b==0){
		x=1;
		y=0;
		return 0;
	}
	inv(b,a%b);
	long long temp=x;
	x=y;
	y=temp-((long long)a/b)*y;
	return x;
}
long long pow(long long a){
	long long b=mod-2;
	long long w=a;
	long long v=1;
	while(b>0){
		if(b&1){
			v=v*w;
			v%=mod;
		}
		w=w*w;
		w%=mod;
		b=b>>1;
	}
	return v;
}
int main(){
	int N,L,R,i,j;
	D[0]=1;D[1]=0;D[2]=1;
	fact[0]=fact[1]=1;
	fact[2]=2;
	for(i=3;i<101;i++){
		D[i]=D[i-1]+D[i-2];
		D[i]%=mod;
		D[i]=D[i]*(long long)(i-1);

		D[i]%=mod;
		fact[i]=(long long)i*fact[i-1];
		fact[i]%=mod;
	}

	long long **pascal=new long long *[101];
	for(i=0;i<101;i++)
		pascal[i]=new long long [i+1];

	pascal[0][0]=0;
	for(i=1;i<101;i++){
		pascal[i][0]=pascal[i][i]=1;
		for(j=1;j<i;j++){
			pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
			pascal[i][j]%=mod;
		}
	}
	IN(N);IN(L);IN(R);
	long long ans=0;
	for(i=L;i<=R;i++){
		long long temp=(pascal[N][i]*D[i])%mod;
		ans+=temp;
		ans%=mod;
	}
	long long temp=pow(fact[N]);
	ans=ans*temp;
	ans%=mod;
	printf("%lld\n",ans );
}
