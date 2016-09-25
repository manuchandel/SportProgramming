#include <bits/stdc++.h>
#define MAX 100009
#define mod 1000000007
#define ll long long
#define ini(x) scanf("%d",&x);
#define inl(x) scanf("%lld",&x);
#define type double
using namespace std;
struct P{
  ll n;
  ll sum;
};
P dp[12][2];
P findsum(int A[],int i,bool tight){
  if(i<0){
    P p;
    p.n=1;
    p.sum=0;
    return p;
  }
  if(dp[i][tight].n!=0)
    return dp[i][tight];
  int j,k;
  P sum;
  sum.n=0;
  sum.sum=0;
  P temp=findsum(A,i-1,0);
  if(tight){
    for(j=0;j<A[i];j++){
      P temp=findsum(A,i-1,0);

      sum.sum+=(ll)j*temp.n;
      sum.n+=temp.n;
      sum.sum+=temp.sum;
    }
    P p=findsum(A,i-1,1);
    sum.sum+=(ll)A[i]*p.n;
    sum.sum+=p.sum;
    sum.n+=p.n;

  }else{
    for(j=0;j<10;j++){
      P temp=findsum(A,i-1,0);

      sum.sum+=(ll)j*temp.n;
      sum.n+=temp.n;
      sum.sum+=temp.sum;
    }
 }
 dp[i][tight]=sum;
return sum;
}

int main(){
  int T,i;
  int A[12];
  int a,b;
  ini(a);ini(b);
  while(a!=-1){
    
    i=0;
    int temp=max(0,a-1);
    while(temp>0){
      A[i]=temp%10;
      temp/=10;
      i++;
    }
    memset(dp,0,sizeof(dp));
    ll suma=findsum(A,i-1,1).sum;
    //cout<<ap.sum<<" "<<ap.n<<endl;
    
    i=0;
    temp=b;
    while(temp>0){
      A[i]=temp%10;
      temp/=10;
      i++;
    }
    memset(dp,0,sizeof(dp));
    ll sumb=findsum(A,i-1,1).sum;
    printf("%lld\n",sumb-suma);
    ini(a);ini(b);
  }
}
