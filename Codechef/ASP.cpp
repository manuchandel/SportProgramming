#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,T,i,count,l;
  bool flag;
  int *A=new int[1000000];
  scanf("%d",&T);
  while(T--){
    count=0;
    flag=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&A[i]);
    i=0;
    while(i<n-1){
      if(A[i]<A[i+1])
        i++;
      else{
        swap(A[i],A[i+1]);
        i+=2;
      }
    }
    for(i=0;i<n-1;i++){
      if(A[i]<A[i+1])
        count++;
    }
    if(count!=n-1)
      flag=0;
    if(flag)
      printf("YES\n");
    else printf("NO\n");
  }
}

