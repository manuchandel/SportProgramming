#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
#define FOR(a,b) for(a=0;a<b;a++)
int main(){
  int i,T;
  unsigned int a;
  int k;
  scanf("%d",&T);
  while(T--){
    scanf("%u%d",&a,&k);
    bitset<32> bits(a);
    bitset<32> bita;
    int p=0;
    i=31;
    if(k>0 && a>0){
      bita.set(0);
      k--;
      i=31;
      while(!bits[i])i--;
      p=i;
      if((a & (a-1))==0){ //a is a power of two
        i=p-1;
        while(k>0 && i>0){
          bita.set(i);
          i--;
          k--;
        }
      }else if(k>0){
        bool process=0;
        i=p;
        if(bits.count()<=k)
          process=1;
        while(i>0 && k>0){
          if(bits[i]){
            bita.set(i);
            k--;
          }
          i--;
        }
        if(process){
          i=1;
          while(!bita[i])i++;
          bita.reset(i);
          k++;
          i--;
          while(i>0 && k>0){
            bita.set(i);
            i--;
            k--;
          }
        }
      }
    }
    if(bita.to_ulong()%2==1)
      printf("%lu\n",bita.to_ulong());
    else printf("-1\n");
  }
}
