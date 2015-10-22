#include <stdio.h>
#include <string.h>
#define FOR(a,b) for(a=0;a<b;a++)
bool isCeil(int a[]){
  int i;
  FOR(i,10)
    if(i!=3 && i!=8 && i!=5 && a[i]>0)
      return 0;
  if(a[8]>=a[5] && a[5]>=a[3])
    return 1;
  return 0;
}
int main(){
  int i;
  int d;
  char c;
  int a[10]={0};
  int N,count=0;
  scanf("%d",&N);
  getchar();
  while(N--){
    i=0;
    c=getchar();
    while((c=getchar())!='\n'){
      d=c-'0';
      if(d<10 && d>=0)
        a[d]+=1;
      else if(c==' ')
        memset(a,0,sizeof(a));
    }
    if(isCeil(a))
      count++;
    memset(a,0,sizeof(a));
  }
  printf("%d\n",count );
}
