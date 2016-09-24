#include <bits/stdc++.h>
#define MAX 100009
#define mod 1000000007
#define ll long long
#define in(x) scanf("%d",&x);
#define type double
using namespace std;

bool check(ll arr[],int N,int K,ll pages){
  ll sum=0;
  int i,j,k;
  i=0;
  ll cumsum=0;
  k=1;
  while(i<N and k<=K){

    if(cumsum+arr[i]<=pages){
      cumsum+=arr[i];
      i+=1;
      
    }else{
      cumsum=0;
      k+=1;
    }
  }
  //cout<<k<<" "<<K<<" "<<pages<<endl;
  if(k<=K)
    return true;
  return false;
}
int dp[500][500];

bool check(int i,int k,ll arr[],int N,int K,ll pages){
  if(k<K and i==N)
    return false;
  if(k==K and i<N){
    return false;
  }
  if(k==K and i==N)
    return true;
  if(dp[k][i]!=-1)
    return dp[k][i];

  int j;
  ll sum=0;
  for(j=i;j<N;j++){
    
    sum+=arr[j];
    if(sum<=pages){
      if(check(j+1,k+1,arr,N,K,pages)){
        for(int l=i;l<=j;l++)
          dp[k][l]=1;
        return true;
      }
    }else{
      dp[k][i]=0;
      return false;
    } 
  }
}
int main(){
  int T,m,k,i,j,l;
  in(T);
  ll arr[500];
  
  while(T--){
    in(m);in(k);
    memset(dp,-1,sizeof(dp));
    ll sum=0;
    for(i=0;i<m;i++){
      int temp;
      in(temp);
      arr[i]=temp;
      sum+=temp;
    }
    
    ll l=0,r=sum;
    ll x;
    while(l<=r){
      int mid=(l+r)>>1;
      if(check(arr,m,k,mid)){
        x=mid;
        r=mid-1;
      }else{
        l=mid+1;
      }
      //cout<<l<<" "<<r<<endl;
    }
    if(k==1){
      for(j=0;j<m;j++)
        printf("%lld ",arr[j]);
      printf("\n");
    }
    else{
      vector<vector<ll> >v;
      v.resize(k);
      check(0,0,arr,m,k,x);
      i=0;j=0;
      while(j<m){
        if(dp[i][j]==1){
          v[i].push_back(arr[j]);
          j++;
        }else{
          i++;
        }
      }
      for(i=0;i<v[0].size();i++)
        printf("%lld ",v[0][i]);
      for(i=1;i<k;i++){
        printf("/ ");
        for(j=0;j<v[i].size();j++)
          printf("%lld ",v[i][j]);
      }
      printf("\n");
    }

  }
}
