#include <stdio.h>
#include <limits.h>
#define FOR(a,b) for(a=0;a<b;a++)
int main()
{
  int i;
  int T;  //test cases
  int N;  //no of indegrients
  int sum;
  int min,in;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    sum=0;
    min=INT_MAX;
    FOR(i,N){
      scanf("%d",&in);
      sum+=in;
      if(in<min)
        min=in;
    }
    if(min<2)
      sum=-1;
    else {
      sum-=min;
      sum+=2;
    }
    printf("%d\n",sum);
  }
}
