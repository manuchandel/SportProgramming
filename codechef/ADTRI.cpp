#include <cstdio>
#include <iostream>
#include <string.h>
#include <cmath>
#include <vector>
#define MAX 5000000
using namespace std;
bool *pythagoren=new bool[MAX+1];
void preprocess(){
  int i,j,k;
  for(i=0;i<=MAX;i++)
    pythagoren[i]=0;
  for(i=1;i<2240;i++){
    for(j=i+1;j<2240;j++){
      k=i*i+j*j;
      if(k <= MAX)
        pythagoren[k]=1;
    }
  }
  for(i=1;i<=MAX;i++){
    if(pythagoren[i]){
      for(j=2;i*j<=MAX;j++)
        pythagoren[j*i]=1;
    }
  }
}
int main(){
  int T,N;
  preprocess();
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    if(pythagoren[N])
      printf("YES\n");
    else printf("NO\n");
  }
}
