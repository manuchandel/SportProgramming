#include <bits/stdc++.h>
#define MAX 100009
#define mod 1000000007
#define ll long long
#define ini(x) scanf("%d",&x);
#define inl(x) scanf("%lld",&x);
#define type double
using namespace std;
ll dp[101][33000];
ll permutations[101][33000];
void solve(int arr[],int N){
  int i,j,k,l;
  memset(dp,0,sizeof(dp));
  memset(permutations,0,sizeof(permutations));
  vector<vector<int> > v;
  v.resize(N+1);
  int n=(1<<N);
  for(i=0;i<n;i++){
    bitset<33> bits(i);
    v[bits.count()].push_back(i);
  }
  for(i=0;i<N;i++){
    int mask=(1<<i);
    dp[arr[i]][mask]=arr[i]*2+1;
    permutations[arr[i]][mask]+=1;
  }

  for(i=0;i<N;i++){
    for(j=0;j<v[i].size();j++){
      int mask=v[i][j];
      for(k=0;k<N;k++){
        int hmask=(1<<k);
        int height=arr[k];
        //cout<<mask<<" "<<hmask<<endl;
        if((mask&hmask)==0){
          int newmask=mask|hmask;
          for(l=0;l<N;l++){
            if(dp[arr[l]][mask]>0){
              //cout<<"working"<<endl;
              ll peri=dp[arr[l]][mask]-arr[l]+1+abs(arr[l]-height)+height;
              if(peri>dp[height][newmask]){
                dp[height][newmask]=peri;
                permutations[height][newmask]=permutations[arr[l]][mask];
              }else if(peri==dp[height][newmask]){
                permutations[height][newmask]+=permutations[arr[l]][mask];
              }
              
            }
          }
        }
      }
    }
  }
  ll maxperi=0;
  ll perm=0;
  int allmask=(1<<N)-1;
  for(i=0;i<N;i++){
    maxperi=max(maxperi,dp[arr[i]][allmask]);
  }
  for(i=0;i<N;i++){
    if(dp[arr[i]][allmask]==maxperi)
      perm+=permutations[arr[i]][allmask];
  }
  maxperi+=N;
  printf("%lld %lld\n",maxperi,perm);
}

int main(){
  int n,i,j,k;
  int arr[15];
  
  while(1){
    ini(n);
    if(n==0)
      break;
    for(i=0;i<n;i++){
      ini(arr[i]);
    }
    solve(arr,n);
  }
}
