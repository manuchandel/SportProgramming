#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int N,T;
  char Q[1000];
  char c;
  int W[1001];
  int i,count=0;
  scanf("%d",&T);
  while(T--){
    count=0;
    scanf("%d",&N);
    for(i=0;i<N;i++)
      cin>>Q[i];
    for(i=0;i<N;i++){
      cin>>c;
      if(c==Q[i])
        count++;
    }
    scanf("%d",&W[0]);
    for(i=1;i<N;i++){
      scanf("%d",&W[i]);
      W[i]=max(W[i],W[i-1]);
    }
    scanf("%d",&W[N]);
    printf("%d\n",W[count]);
  }
}
