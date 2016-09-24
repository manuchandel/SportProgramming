#include <bits/stdc++.h>
#define MAX 100009
#define mod 1000000007
#define ll long long
#define ini(x) scanf("%d",&x);
#define inl(x) scanf("%lld",&x);
#define type double
using namespace std;

int solve(int A[], int n, int B[],int m){
  int dp[m+1];
  //cout<<"working"<<endl;
  int i,j,k;
  dp[m]=0;
  for(i=m-1;i>=0;i--){
    dp[i]=0;
    if(A[n-1]==B[i]){
      dp[i]=1;
    }
    dp[i]=max(dp[i],dp[i+1]);
  }
  for(i=n-2;i>=0;i--){
    int diag=dp[m-1];
    if(A[i]==B[m-1])
      dp[m-1]=1;
    
    for(j=m-2;j>=0;j--){
      int temp=dp[j];
      if(A[i]==B[j]){
        dp[j]=1+diag;
      }else{
        dp[j]=max(dp[j],dp[j+1]);
      }
      diag=temp;
    }
  }
  return dp[0];
}

int main(){
  int n,i,j,k,T,N,M;
  int B[2000];
  int A[2000];
  ini(T);
  while(T--){
    int ans=0;
    int temp;
    ini(temp);
    i=0;
    while(temp!=0){
      A[i]=temp;i++;
      ini(temp);
    }
    N=i;
    ini(temp);
    while(temp!=0){
      i=0;
      while(temp!=0){
        B[i]=temp;
        i++;
        ini(temp);
      }
      ans=max(ans,solve(A,N,B,i));
      ini(temp);
    }

    printf("%d\n",ans);
  }
}
