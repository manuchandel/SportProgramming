#include <cstdio>
#define FOR(a,b)  for(a=0;a<b;a++)
int main()
{
  int i;
  int T;  //test cases
  int N;  //no of players
  int current,prev,prev2;
  int ans;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    ans=0;
    scanf("%d",&prev);
    scanf("%d",&current);
    if(current!=prev)
      ans++;
    FOR(i,N-2){
      prev2=prev;
      prev=current;
      scanf("%d",&current);
      if(prev!=current || prev!=prev2)
        ans++;
    }
    if(current!=prev)
      ans++;
    printf("%d\n",ans);
  }
}
