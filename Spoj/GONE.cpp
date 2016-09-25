#include <bits/stdc++.h>
#define MAX 100009
#define mod 1000000007
#define ll long long
#define ini(x) scanf("%d",&x);
#define inl(x) scanf("%lld",&x);
#define type double
using namespace std;
int dp[12][100][2];
bool prime[100];
void sieve(){
  int i,j;
  for(i=2;i<100;i++){
    prime[i]=1;
  }
  prime[0]=prime[1]=0;
  for(i=2;i<=10;i++){
    for(j=i*i;j<100;j+=i)
      prime[j]=0;

  }

}
int foo(int arr[],int i,int sum,bool tight){
  if(i<0){
    //printf("%d\n",abs(oddsum-esum) );
    if(prime[sum])
      return 1;
    return 0;
  }
    
  if(dp[i][sum][tight]!=-1)
    return dp[i][sum][tight];
  int j,k;
  int numbers=0;
  if(tight){
    for(j=0;j<arr[i];j++){
        numbers+=foo(arr,i-1,j+sum,0);

    }
    numbers+=foo(arr,i-1,arr[i]+sum,1);
  }
  else{
    for(j=0;j<=9;j++){
        numbers+=foo(arr,i-1,j+sum,0);
    }
  }
  dp[i][sum][tight]=numbers;
  return numbers;
}

int main(){
  int T,i;
  int A[12];
  int a,b;
  sieve();
  ini(T);
  while(T--){
    ini(a);ini(b);
    i=0;
    int temp=max(0,a-1);
    while(temp>0){
      A[i]=temp%10;
      temp/=10;
      i++;
    }
    memset(dp,-1,sizeof(dp));
    int la=foo(A,i-1,0,1);
    //cout<<ap.sum<<" "<<ap.n<<endl;
    
    i=0;
    temp=b;
    while(temp>0){
      A[i]=temp%10;
      temp/=10;
      i++;
    }
    memset(dp,-1,sizeof(dp));
    int lb=foo(A,i-1,0,1);
    printf("%d\n",lb-la);
    //ini(a);ini(b);
  }
}
