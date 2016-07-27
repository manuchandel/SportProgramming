#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
long long a[19][163][1459];
bool seen[19][163][1459];
int dig[19];
long long gcd(long long a,long long b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
long long dp(int idx,int sum,int sqsum,bool small){
	if(idx==-1){
		if(gcd(sum,sqsum)==1)
			return 1;
		return 0;
	}
	if(small && a[idx][sum][sqsum]!=-1)
		return a[idx][sum][sqsum];
	long long ans=0;
	int end;
	if(small){
		end=9;
	}else end=dig[idx];

	for(int i=0;i<=end;i++){
		ans+=dp(idx-1,sum+i,sqsum+i*i,small || i<end);
	}
	if(small)
		a[idx][sum][sqsum]=ans;
	return ans;
}
long long solve(long long N){
	int len=0;
	while(N>0){
		dig[len++]=N%10;
		N/=10;
	}
	return dp(len-1,0,0,0);
}
int main(){
	memset(a,-1,sizeof(a));
	int T;
	long long l;
	long long r;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",solve(r)-solve(l-1));
	}


}
