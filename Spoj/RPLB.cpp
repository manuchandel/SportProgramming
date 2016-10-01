#include <bits/stdc++.h>
#define MAX 3000
#define mod 100000007
#define ll long long
#define ini(x) scanf("%d",&x);
#define inl(x) scanf("%lld",&x);
#define ind(x) scanf("%lf",&x);
#define type double
using namespace std;
int dp[1001][1001];
int foo(int n, int k, int arr[]){
    int i,j;
    dp[n-1][0]=0;
    dp[n-2][0]=0;
    for(i=1;i<=k;i++){
        if(arr[n-1]==i)
          dp[n-1][i]=i;
        else dp[n-1][i]=dp[n-1][i-1];
    }
    for(i=1;i<=k;i++){
      if(arr[n-2]==i)
          dp[n-2][i]=i;
      else dp[n-2][i]=max(dp[n-1][i],dp[n-2][i-1]);
    }
    for(i=n-3;i>=0;i--){
      for(j=k;j>=0;j--){
        dp[i][j]=-1;
        if(j-arr[i]>=0 and i+2<n)
          dp[i][j]=max(dp[i][j],max(arr[i]+dp[i+2][j-arr[i]],dp[i+2][j]));
        dp[i][j]=max(dp[i][j],dp[i+1][j]);
      }
    }
    /*
    for(i=0;i<n;i++){
      for(j=1;j<=k;j++)
        cout<<dp[i][j]<<" ";
      cout<<endl;
    }
    */
    return dp[0][k];
}
int main()
{
  int T,t,i;
  ini(T);
  int arr[1001];
  int n,k;
  for(t=1;t<=T;t++){
    ini(n);ini(k);
    for(i=0;i<n;i++)
      ini(arr[i]);
    printf("Scenario #%d: %d\n",t,foo(n,k,arr));
  }
}
