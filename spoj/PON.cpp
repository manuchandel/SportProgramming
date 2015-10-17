#include <stdio.h>
#include <cstdlib>
#define ll long long
using namespace std;
//n=2^rs+1
//accurcy paramater k is assumed 1
ll aMultiplybModc(ll a,ll b,ll c)
{
	ll x=0,y=a%c;
	while(b>0)
	{
		if(b%2==1)
			x=(y+x)%c;
		y=(y<<1)%c;
		b=b>>1;
	}
	return x;
}
ll aPowerpModN(int a,ll p,ll n)
{
	ll x=1,y;
	y=a%n;
	while(p>0){
		if(p%2==1)
			x= aMultiplybModc(x,y,n);
		y= aMultiplybModc(y,y,n);
		p=p>>1;
	}
	return x;
}
bool MillerRabin(long long b[],long long n)//b[0]=r b[1]=s
{
	if(n==2||n==3)
		return 1;
	if(n%2==0||n%3==0||n%5==0||n%7==0)
		return 0;
	//srand(time(0));
	int k=1;//parameter for accuracy
	ll j,a,temp;
	if(a>6)
		a=rand()%(n-2)+2;
	else a=6;
	a=aPowerpModN(a,b[1],n);
	j=0;
	while(a!=1&&j<b[0]-1&&a!=n-1){
		a=aMultiplybModc(a,a,n);
		j++;
	}
	if(a!=n-1&&j>0)
		return 0;
	if(a!=1&&a!=n-1&&j==0)
		return 0;
	return 1;
}
void parameter(ll a[],ll n){//a[0]=r a[1]=s
	a[0]=a[1]=0;
	while(n%2==0){
		n=n>>1;
		a[0]++;
	}
	a[1]=n;
}
int main(){
	ll n;
	int t;
	ll a[2];
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		parameter(a,n-1);
		if(MillerRabin(a,n))
			printf("YES\n");
		else
			printf("NO\n");
	}
}
