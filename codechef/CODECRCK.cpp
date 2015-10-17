#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
#include <algorithm>
#define MAX 1000000
#define ll long long
#define FOR(i,a,n) for(i=a;i<n;i++)
using namespace std;
int main(){
  long long i,k,s;
  double a,b,c,d;
  long long numpower=0,denopower=0;
  scanf("%lld%lld%lld",&i,&k,&s);
  cin>>a>>b;
  if(abs(i-k)%2==1){
    i++;
    c=sqrt(2)*(a+b)-sqrt(6)*(a-b);
    d=sqrt(2)*(a-b)+sqrt(6)*(a+b);
    a=c;
    b=d;
  }
  if(k>=i){
    numpower=(k-i)*2;
  }else{
    denopower=(i-k)*2;
  }
  if(s>=0)
    denopower+=s;
  else numpower+=abs(s);
  a+=b;
  if(denopower>=numpower){
    denopower-=numpower;
    while(denopower>0 && abs(a)>=0.01){
      a/=2;
      denopower--;
    }
    printf("%0.5f\n",a);
  }else{
    numpower-=denopower;
    while(numpower>0){
      a*=2;
      numpower--;
    }
    printf("%0.5f\n",a);
  }
}
