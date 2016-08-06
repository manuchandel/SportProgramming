#include <bits/stdc++.h>
#define IN(L) scanf("%d",&L)
#define mod 1000000007
using namespace std;

int main(){
	int N,K,i,j;
	int brushes[1001];
	IN(N);IN(K);
	for(i=0;i<K;i++)
		IN(brushes[i]);

	int superbrushes[1001];
	memset(superbrushes,0,sizeof(superbrushes));
	superbrushes[0]=1;
	for(i=0;i<K;i++){
		for(j=brushes[i];j<=N;j++)
			superbrushes[j]=superbrushes[j]|superbrushes[j-brushes[i]];
	}
	long long U[1001];
	long long P[1001];
	memset(U,0,sizeof(U));
	memset(P,0,sizeof(P));
	U[0]=1;
	for(i=1;i<=N;i++){
		U[i]=U[i-1]+P[i-1];
		U[i]%=mod;
		for(j=1;j<=i;j++){
			P[i]+=U[i-j]*(long long)superbrushes[j];
			P[i]%=mod;
		}
	}
	printf("%lld\n",(P[N]+U[N])%mod);
}
