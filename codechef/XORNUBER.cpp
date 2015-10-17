#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string.h>
#define FOR(a,b) for(int a=0;a<b;a++)
using namespace std;
int xorVal(int A){
  if(A%2==0)
    return -1;
  if(A==1)
    return 2;
  A=A+1;
  if(!(A&(A-1))){
    A=A-1;
    A=A>>1;
    return A;
  }else return -1;
 
}
 
int main()
{
  int T,A;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&A);
    printf("%d\n",xorVal(A));
  }
}
