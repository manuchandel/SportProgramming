#include <bits/stdc++.h>
#define MAX 100009
#define mod 1000000007
#define ll long long
#define ini(x) scanf("%d",&x);
#define inl(x) scanf("%lld",&x);
#define type double
using namespace std;
ll g[MAX][3];
ll dp[MAX][3];
const ll inf=(ll)1<<60;

int main(){
  int n,i,j,k,T,N,M;
  ini(n);
  k=1;
  while(n!=0){
    for(i=0;i<n;i++){
      for(j=0;j<3;j++)
        inl(g[i][j]);
    }

    dp[0][0]=inf;
    dp[0][1]=g[0][1];
    dp[0][2]=dp[0][1]+g[0][2];
    for(i=1;i<n;i++){
      dp[i][0]=g[i][0]+min(dp[i-1][0],dp[i-1][1]);
      dp[i][1]=g[i][1]+min(dp[i-1][0],min(dp[i-1][2],min(dp[i][0],dp[i-1][1])));
      dp[i][2]=g[i][2]+min(dp[i][1],min(dp[i-1][1],dp[i-1][2]));
    }
    printf("%d. %lld\n",k,dp[n-1][1]);
    k+=1;
    ini(n);
  }
}
