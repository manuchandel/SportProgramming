#include <stdio.h>
#define ll long long
#define max 200001
using namespace std;
ll charr[2][2];
ll arr[50][2];
ll num[2];
ll nfact[max];
ll extendedEuclid(ll a,ll b){
	int orig_a=a, orig_b=b;
	ll i=0,y=2,l=0;
	while(y!=1&&y!=0){
		arr[i][0]=1;
		arr[i][1]=-1*(int)a/b;
		y=a%b;
		a=b;
		b=y;
		i++;
	}
	if(y==0)
		return -1;
	l=i;
	for(i=l-1;i>0;i--){
		arr[i-1][0]*=arr[i][1];
		arr[i-1][1]*=arr[i][1];
		arr[i-1][1]+=arr[i][0];
	}
	if(arr[0][0]<0)
		arr[0][0]+=orig_b;
	return arr[0][0];
}
ll chineseRemainder(){
	int i,l=2;
	ll mod=1000000006,return_ans=0;
	for(i=0;i<l;i++){
		num[i]=mod/charr[i][1];
		num[i]=(num[i]*extendedEuclid(num[i],charr[i][1]))%mod;
		num[i]=(num[i]*charr[i][0])%mod;
	}
	for(i=0;i<l;i++){
		return_ans+=num[i];
		if(return_ans>mod)
			return_ans%=mod;
	}
	return return_ans;

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
void calculate_nfact(){
	int i;
	ll x=1,p=500000003;
	nfact[0]=nfact[1]=1;
	for(i=2;i<=max;i++){
		x=(x*i)%p;
		nfact[i]=x;
	}
}
ll calculate_answer(ll n,ll a,ll b){
	ll mod=1000000007;
	ll mod1=500000003;
	ll mod2=2;
	charr[0][1]=mod1;
	charr[1][1]=mod2;
	ll y,x,count_num=0,count_deno=0;
	y=n;x=2;
	while(x<=y){
		count_deno+=y/x;
		x=(x<<1);
	}
	y=(y<<1);
	x=2;
	while(x<=y){
		count_num+=y/x;
		x=(x<<1);
	}
	count_deno=(count_deno<<1);
	if(count_deno==count_num)
		charr[1][0]=1;
	else charr[1][0]=0;
	x=nfact[n];
	y=nfact[2*n];
	x=(x*x)%mod1;
	x=extendedEuclid(x,mod1);
	x=(x*y)%mod1;
	charr[0][0]=x;
	x=chineseRemainder();
	x=a_power_p_mod_m(x,b,mod-1);
	x=a_power_p_mod_m(a,x,mod);
	return x;
}
int main(){
	/*ifstream o1("input.txt");
	ofstream o2;
	o2.open("output.txt");*/
	calculate_nfact();
	int T;
	ll n,a,b,answer;
	scanf("%d",&T);
	//o1>>T;
	while(T--){
		scanf("%lld%lld%lld",&a,&b,&n);
		//o1>>n>>k>>p;
		answer=calculate_answer(n,a,b);
		/*o2<<answer;
		o2<<"\n";*/
		printf("%lld\n",answer);
	}
	/*o2.close();
	o1.close();*/
}


