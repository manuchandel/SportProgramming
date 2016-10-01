#include <bits/stdc++.h>
#define MAX 3000
#define mod 100000007
#define ll long long
#define ini(x) scanf("%d",&x);
#define inl(x) scanf("%lld",&x);
#define ind(x) scanf("%lf",&x);
#define type double
using namespace std;
vector<int> prime;
ll dp[7994][5];
void sieve(){
  int i,j;
  bool p[10001];
  for(i=2;i<10001;i++)
    p[i]=1;
  p[0]=p[1]=0;
  for(i=2;i*i<=10001;i++)
    if(p[i])
      for(j=i*i;j<10001;j+=i)
        p[j]=0;
    prime.push_back(2);
  for(i=2;i<7994;i++)
    if(p[i] and i%4 ==1){
      prime.push_back(i);
      //cout<<i<<endl;
    }
}

void filldp(){
  int i,j;
  memset(dp,0,sizeof(dp));
  dp[0][0]=1;
  for(i=0;i<7994;i++){
    for(j=1;j<=4;j++){
      if(i-j>=0)
        dp[i][j]=dp[i-j][j];
      dp[i][j]+=dp[i][j-1];
    }
  }
}
int main()
{
  sieve();filldp();
  int t;
  ini(t);
  while(t--){
    int n,k;
    ini(n);ini(k);
    printf("%lld\n",dp[prime[n-1]][k]);
  }
}
