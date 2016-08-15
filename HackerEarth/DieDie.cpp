#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long

using namespace std;

ll power(ll a, ll b){
	ll x=1;
	ll y=a%mod;
	while(b>0){
		if(b&1){
			x=x*y;
			x%=mod;
		}
		b=b>>1;
		y=y*y;
		y%=mod;
	}
	return x;
}

int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--){
		ll n;
		scanf("%lld",&n);
		ll deno=power(2,n-1);
		ll ans=power(deno,mod-2);
		printf("%lld\n",ans );
	}


	

}
