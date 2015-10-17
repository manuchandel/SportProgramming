#include <stdio.h>
#define FOR(a,b) for(a=0;a<b;a++)

struct planInfo{
  int M;  //no of months
  float R;  //calling rate
  int C;  //cost of plans
};
planInfo plans[100];
int calculateAnswer(int N,int U,float D){
  int i;
  float new_cost=(float)U*D;
  float temp_cost;
  int plani=-1;
  FOR(i,N){
    temp_cost=(float)plans[i].R* U;
    temp_cost=(float)temp_cost*plans[i].M;
    temp_cost+=plans[i].C;
    temp_cost/=plans[i].M;
    if(new_cost > temp_cost){
      new_cost=temp_cost;
      plani=i;
    }
  }
  return (plani+1);
}
int main()
{
  int i;
  int T;  //test cases
  float D;  //default rate
  int U;  //no of minutes
  int N;  //no of plans
  scanf("%d",&T);
  while(T--){
    scanf("%f%d%d",&D,&U,&N);
    FOR(i,N)
      scanf("%d%f%d",&plans[i].M,&plans[i].R,&plans[i].C);
    printf("%d\n",calculateAnswer(N,U,D) );
  }
}
