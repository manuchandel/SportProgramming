#include <cstdio>
#define MAX 50000
#define FOR(a,b) for(a=0;a<b;a++)
int main()
{
  int i;
  int T;  //test cases
  int n;
  long long *arr=new long long[MAX];
  long long sum;
  scanf("%d",&T);
  while(T--){
    sum=0;
    scanf("%d",&n);
    FOR(i,n){
      scanf("%lld",&arr[i]);
      sum+=arr[i];
    }
    sum/=(n-1);
    FOR(i,n)
      printf("%lld ",sum-arr[i]);
    printf("\n");
  }
}
