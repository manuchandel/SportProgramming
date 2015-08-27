#include <stdio.h>
#define mod 1000000007
#define ll long long
#define FOR(a,b) for(a=0;a<b;a++)
ll ten[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000};
ll getSum(ll n1){
  n1*=(n1+1);
  return (n1>>1);
}
int solve(ll n1,ll n2){
  int i=0,j=0,k=0;
  while(n1>ten[i]) i++;
  while(n2>ten[j]) j++;
  ll ans=0,temp;
  if(i==j){
    ans=(getSum(n2)-getSum(n1)+n1)*i;
    ans%=mod;
    return (int)ans;
  }
  temp=getSum(ten[i]-1)-getSum(n1)+n1;
  temp%=mod;
  temp*=i;
  temp%=mod;
  ans=(ans+temp)%mod;
  temp=getSum(n2)-getSum(ten[j-1])+ten[j-1];
  temp%=mod;
  temp*=j;
  temp%=mod;
  ans=(ans+temp)%mod;
  for(k=i+1;k<j;k++){
    temp=getSum(ten[k]-1)-getSum(ten[k-1])+ten[k-1];
    temp%=mod;
    temp*=k;
    temp%=mod;
    ans=(ans+temp)%mod;
  }
  return (int)ans;
}

int main(){
  int T;
  ll n1,n2;
  scanf("%d",&T);
  while(T--){
    scanf("%lld%lld",&n1,&n2);
    printf("%d\n",solve(n1,n2));
  }
}
