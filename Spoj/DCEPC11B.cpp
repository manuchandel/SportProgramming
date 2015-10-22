#include <stdio.h>
#define ll long long
using namespace std;
ll a_mul_b_mod_m(ll a, ll b, ll m){
	ll x=0, y=a%m;
	while(b>0){
		if(b%2==1)
			x=(x+y)%m;
		y=(y<<1)%m;
		b=b>>1;
	}
	return x;
}
ll a_power_p_mod_m(ll a, ll p, ll m){
	ll x=1,y=a%m;
	while(p>0){
		if(p%2==1)
			x=(x*y)%m;
		y=(y*y)%m; 
		p=p>>1;
	}
	return x;
}
ll calculate_a(ll n,ll p,ll m){
	ll x=1;
	while(n<p){
		x=(x*n)%m;
		n++;
	}
	return x;
}
int main(){
	int T;
	ll n,p,answer;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&n,&p);
		answer=a_power_p_mod_m(calculate_a(n+1,p,p),p-2,p);
		answer=p-answer;
		if(n>=p)
			answer=0;
		printf("%lld\n",answer);
	}
}


