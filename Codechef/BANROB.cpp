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
struct Box{
  double val;
  double chef;
  double frnd;
};
Box *A=new Box[MAX];
int main(){
  int T,i,n;
  int M;
  Box box;
  double p;
  double maxVal;
  scanf("%d",&T);
  while(T--){
    maxVal=1000000000;
    cin>>M>>p;
    i=0;
    while(maxVal>= 0.001 && i<M && i<MAX){
      A[i].val=maxVal;
      A[i].chef=0;
      A[i].frnd=0;
      maxVal=p*maxVal;
      i++;
    }
    n=i;
    if((n-1)%2==0){
      A[n-1].chef=A[n-1].val;
    }else A[n-1].frnd=A[n-1].val;
    for(i=n-2;i>=0;i--){
      if(i%2==0){
        A[i].frnd=A[i+1].frnd;
        A[i].chef=A[i].val-A[i].frnd;
      }else{
        A[i].chef=A[i+1].chef;
        A[i].frnd=A[i].val-A[i].chef;
      }
    }
    printf("%0.3f %0.3f\n",A[0].chef,A[0].frnd);
  }
}
