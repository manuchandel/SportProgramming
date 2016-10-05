#include <bits/stdc++.h>
#define MAX 3000
#define mod 100000007
#define ll long long
#define ini(x) scanf("%d",&x);
#define inl(x) scanf("%lld",&x);
#define ind(x) scanf("%lf",&x);
#define type double
using namespace std;

int main(){
  int i,l,k;
  int n;
  ini(k);ini(l);ini(n);
  int a[50];
  for(i=0;i<n;i++){
    ini(a[i]);
  }
  int *arr=new int [1000001];
  arr[1]=1;
  for(i=2;i<1000001;i++){
    if(arr[i-1]==0 or ((i-k)>=0 && arr[i-k]==0) or ((i-l)>=0 && arr[i-l]==0) )
      arr[i]=1;
    else arr[i]=0;
  }
  for(i=0;i<n;i++){
    if(arr[a[i]])
      printf("A");
    else printf("B");
  }
  printf("\n");
}
