#include <cstdio>
#include <cmath>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
struct Pair{
  int x,y;
};
Pair *pair=new Pair[250001];
int manhattenDist(int a,int b){
  int dist=0;
  dist+=abs(pair[a].x-pair[b].x);
  dist+=abs(pair[a].y-pair[b].y);
  return dist;
}
int main(){
  int T,N,a,ans;
  int i,j;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    ans=0;
    FOR(i,N)
      FOR(j,N){
        scanf("%d",&a);
        pair[a].x=i;
        pair[a].y=j;
      }
    for(i=1;i<N*N;i++)
      ans+=manhattenDist(i,i+1);
    printf("%d\n",ans);
  }
}
