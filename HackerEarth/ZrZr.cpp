#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll foo(ll N){
	ll ans=0;
	ll five=5;
	while(N/five > 0){
		ans+=N/five;
		five*=5;
	}
	return ans;
}
int main()
{
    int T;
    ll N;
    scanf("%d",&T);
    while(T--){
    	scanf("%lld",&N);
    	printf("%lld\n",foo(N));
    	
    }
}
