#include <stdio.h>
#include <algorithm>
using namespace std;
#define FOR(a,b) for(a=0;a<b;a++)

int *p=new int[78498];
int *p2=new int [168];
int *p3=new int [25];
bool search(int val,int n){
  int l=0,r=n-1, mid;
  if(val<0)
    return 0;
  while(l<=r){
    mid=(l+r)>>1;
    if(p[mid]==val)
      return 1;
    else if(val>p[mid])
      l=mid+1;
    else r=mid-1;
  }
  return 0;
}
void sieve(){
  int i,j,n=1000000;
  bool *seen=new bool[n];
  FOR(i,n)
    seen[i]=0;
  seen[0]=seen[1]=1;
  FOR(i,1001){
    if(!seen[i])
      for(j=i*i;j<n;j+=i)
        seen[j]=1;
  }
  int count=0;
  FOR(i,n)
    if(!seen[i])
      p[count++]=i;
  delete []seen;
}
int main()
{
  sieve();
  int i,j,n;
  FOR(i,168)
    p2[i]=p[i]*p[i];
  FOR(i,25)
    p3[i]=p2[i]*p[i];
  bool present=0;
  while(1){
    scanf("%d",&n);
    if(n==0)
      break;
    present=0;
    FOR(i,168 && !present){
      FOR(j,25 && !present){
        if(n-p2[i]-p3[j]<0)
          break;
        if(search(n-p2[i]-p3[j],78498)){
          printf("%d %d %d\n",n-p2[i]-p3[j],p[i],p[j]);
          present=1;
        }
      }
    }
    if(!present)
      printf("0 0 0\n");
  }
  delete []p;
  delete []p2;
  delete []p3;

}
