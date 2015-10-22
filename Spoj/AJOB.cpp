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
ll calculate_nfact(ll n,ll p){
	if(n==0||n==1)
		return 1;
	ll x=1;
	n++;
	while(n<p){
		x=a_mul_b_mod_m(n,x,p);
		n++;
	}
	x=a_power_p_mod_m(x,p-2,p);
	x=p-x;
	return x;
}
ll strange_factorial(ll n,ll p){
	if(n<p){
		if(p-n-1>n){
			ll q=1;
			for(int i=2;i<=n;i++)
				q=(q*i)%p;
			return q;
		}
		return calculate_nfact(n,p);
	}
	ll no_of_complete_blocks=n/p;
	ll x=a_power_p_mod_m(p-1,no_of_complete_blocks,p);
	ll y=strange_factorial(n%p,p);
	ll z=strange_factorial(no_of_complete_blocks,p);
	ll answer=(x*y)%p;
	answer=(answer*z)%p;
	return answer;
}
ll calculate_answer(ll n,ll k,ll p){
	ll num_pow=0,deno_pow=0,temp=p,temp_prev;
	while(temp<(n+2)){
		num_pow+=(n+1)/temp;
		if((n+1)/temp>=p)
			temp*=p;
		else temp=n+2;
	}

	temp=p;
	while(temp<(k+2)){
		deno_pow+=(k+1)/temp;
		if((k+1)/temp>=p)
			temp*=p;
		else temp=k+2;
	}
	temp=p;
	while(temp<(n-k+1)){
		deno_pow+=(n-k)/temp;
		if((n-k)/temp>=p)
			temp*=p;
		else temp=n;
	}
	//printf("%lld  %lld\n",num_pow,deno_pow );
	if(num_pow>deno_pow)
		return 0;
	ll num=strange_factorial(n+1,p);
	ll x=strange_factorial(k+1,p);
	ll y=strange_factorial(n-k,p);
	temp=(x*y)%p;
	ll deno=a_power_p_mod_m(temp,p-2,p);
	x=(deno*num)%p;
	return x;
}
int main(){
	/*ifstream o1("input.txt");
	ofstream o2;
	o2.open("output.txt");*/
	int T;
	ll n,k,p,answer;
	scanf("%d",&T);
	//o1>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&k,&p);
		//o1>>n>>k>>p;
		answer=calculate_answer(n,k,p);
		/*o2<<answer;
		o2<<"\n";*/
		printf("%lld\n",answer);
	}
	/*o2.close();
	o1.close();*/
}


