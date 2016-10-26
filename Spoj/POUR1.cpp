#include <bits/stdc++.h>
#define MAX 3000
#define mod 1000000007
#define ll long long
#define ini(x) scanf("%d",&x)
#define inl(x) scanf("%lld",&x)
#define ind(x) scanf("%lf",&x)
using namespace std;
int bucket[2];
int gcd(int a, int b){

  if(b==0)
    return a;
  return gcd(b,a%b);
}
int steps(int cx,int cy, int target){
  int x,y;
  if(target==cx or target==cy)
    return 1;
  if(target==0)
    return 0;
  if(target>cx and target>cy)
    return -1;

  int cf=gcd(cx,cy);
  if(target%cf>0)
    return -1;

  int moves1=0,moves2=0;
  x=0;y=0;
  while(x!=target and y!=target){
    if(x==0){
      moves1++;
      x=cx;
    }else if(y==cy){
      moves1++;
      y=0;
    }else{
      int total=x+y;
      y=min(cy,total);
      x=total-y;
      moves1+=1;
    }

  }
  x=0;y=0;
  while(x!=target and y!=target){
    if(y==0){
      moves2++;
      y=cy;
    }else if(x==cx){
      moves2++;
      x=0;
    }else{
      int total=x+y;
      x=min(cx,total);
      y=total-x;
      moves2++;
    }
  }
  return min(moves1,moves2);

}
int main(){
    int t,a,b,c;
    ini(t);
    while(t--){
      ini(a);ini(b);ini(c);
      printf("%d\n",steps(a,b,c));
    }
   
} 
