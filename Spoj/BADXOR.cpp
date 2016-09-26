#include <bits/stdc++.h>
#define MAX 100009
#define mod 100000007
#define ll long long
#define ini(x) scanf("%d",&x);
#define inl(x) scanf("%lld",&x);
#define type double
using namespace std;

ll K[101];
ll dp[101];
ll const inf=(ll)1<<60;
int main(){
  int T,i,j,t;
  ll A[1024];
  ll B[1024];
  int C[1024];
  ll D[1024];
  ll two[1024];
  two[0]=1;
  for(i=1;i<1024;i++){
    two[i]=(two[i-1]<<1);
    two[i]%=mod;
  }
  int n,m;
  ini(T);
  for(t=1;t<=T;t++){
    ini(n);ini(m);
    for(i=0;i<n;i++){
      ini(C[i]);
    }

    memset(B,0,sizeof(B));
    memset(A,0,sizeof(A));
    memset(D,0,sizeof(D));
    A[0]=1;
    for(i=0;i<m;i++){
      ll temp;
      inl(temp);
      D[temp]=1;
    }
    for(i=0;i<n;i++){
      
      for(j=1023;j>=0;j--){
        B[j]=A[j]+A[C[i]^j];
        B[j]%=mod;
      }
      for(j=0;j<1024;j++){
        if(B[j]!=0)
          A[j]=B[j];
        B[j]=0;
      }


    }
    ll bad=0;
    for(i=0;i<1024;i++){
      bad+=D[i]*A[i];
      bad%=mod;
    }
    
    ll ans=two[n]-bad;
    if(ans<0)
      ans+=mod;
    printf("Case %d: %lld\n",t,ans);
  }
}
