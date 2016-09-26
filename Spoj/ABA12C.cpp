#include <bits/stdc++.h>
#define MAX 100009
#define mod 1000000007
#define ll long long
#define ini(x) scanf("%d",&x);
#define inl(x) scanf("%lld",&x);
#define type double
using namespace std;

ll K[101];
ll dp[101];
ll const inf=(ll)1<<60;
int main(){
  int T,i,j;
  int n,k;
  ini(T);
  while(T--){
    ini(n);ini(k);
    for(i=1;i<=k;i++){
      inl(K[i]);
      if(K[i]==-1)
        K[i]=inf;
    }
    K[0]=inf;

    dp[0]=0;
    for(i=1;i<=k;i++){
      dp[i]=inf;
      for(j=1;j<=i;j++){
        dp[i]=min(dp[i],K[j]+dp[i-j]);
      }
    }
    ll ans=dp[k];
    if(ans==inf)
      ans=-1;
    printf("%lld\n",ans);
  }
}
