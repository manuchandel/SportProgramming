#include <bits/stdc++.h>
#define IN(L) scanf("%d",&L)
#define mod 1000000007
#define ll long long
using namespace std;
int main(){
	ll N,K,i,j;
	scanf("%lld%lld",&N,&K);
	ll A[1001][1001];
	memset(A,0,sizeof(A));
	A[0][0]=1;
	for(i=1;i<=N;i++){
		A[i][0]=A[i][i]=1;
		for(j=1;j<i;j++){
			A[i][j]=A[i-1][j-1]+A[i-1][j];
			A[i][j]%=mod;
		}
	}
	ll F[N+1];
	F[0]=1;
	for(i=1;i<=N;i++){
		F[i]=i*F[i-1];
		F[i]%=mod;
	}

	ll L[N+1];
	memset(L,0,sizeof(L));
	L[1]=1;
	L[0]=1;
	for(i=2;i<=N;i++){
		for(j=0;j<i;j++){
			ll temp=A[i-1][j]*F[j+1];
			temp%=mod;
			temp*=L[i-1-j];
			temp%=mod;
			L[i]+=temp;
			L[i]%=mod;
		}

	}
	cout<<(L[N]*A[N][K])%mod<<endl;


}
