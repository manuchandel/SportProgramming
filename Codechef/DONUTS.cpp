#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX 20001
#define FOR(i,a,n) for(i=a;i<n;i++)
using namespace std;
int *a=new int[MAX];
int foo(int n){
  int p=0,q=n-1,b=0;
  while(p<q){
    if(a[p]>0){
      a[p]-=1;
      a[q-1]+=a[q];
      a[q-1]+=1;
      q--;
      b++;
    }else p++;
  }
  return b;
}
int main(){
  int i;
  int T,N,M,b;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&N,&M);
      FOR(i,0,M)
        scanf("%d",&a[i]);
    if(N==M)
      printf("%d\n",M/2);
    else{
      sort(a,a+M);
      printf("%d\n",foo(M));
    }
  }
}

