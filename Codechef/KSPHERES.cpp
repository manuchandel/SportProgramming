#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#define mod 1000000007
using namespace std;
void method(vector<long long> &v,int C){
  int i,j,k,n=v.size();
  if(n==0){
    for(i=0;i<C;i++)
      printf("0 ");
    printf("\n");
    return;
  }
  long long *a=new long long[n+1];
  long long *b=new long long[n+1];
  long long c[2];
  for(i=0;i<n+1;i++){
    a[i]=0;b[i]=0;
  }
 
  b[0]=mod-v[0];
  b[1]=1;
  k=2;
  for(i=1;i<n;i++){
    c[0]=mod-v[i];
    c[1]=1;
    for(j=0;j<k;j++)
      a[j]=0;
    for(j=0;j<k;j++){
      long long temp=b[j]*c[0];
      if(temp<0) temp+=mod;
      temp%=mod;
      a[j+0]+=temp;
      a[j+0]%=mod;
      a[j+1]+=b[j];
      a[j+1]%=mod;
    }
    long long *d=a;
    a=b;
    b=d;
    k++;
  }
  for(i=n-1;i>=0;i-=2){
    b[i]=0-b[i];
    if(b[i]<0)
      b[i]+=mod;
  }
  i=n-2;
  k=0;
  while(k<C && i>=0){
    printf("%lld ",b[i]);
    i--;k++;
  }
  while(k<C){
    printf("0 ");k++;
  }
  printf("\n");
 
}
int main(){
  int N,M,C;
  long long U[1001];
  long long  L[1001];
  vector<long long> v;
  int i,j,k,l;
  int radii;
  scanf("%d%d%d",&N,&M,&C);
  for(i=0;i<=1000;i++){
    U[i]=0;
    L[i]=0;
  }
  for(i=0;i<N;i++){
    scanf("%d",&radii);
    U[radii]+=1;
  }
  for(i=0;i<M;i++){
    scanf("%d",&radii);
    L[radii]+=1;
  }
  for(i=1;i<=1000;i++){
    long long temp=L[i]*U[i];
    if(temp>0)
      v.push_back(temp%mod);
  }
  N=v.size();
  method(v,C);
}
