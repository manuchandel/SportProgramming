#include <bits/stdc++.h>
#define MAX 3000
#define mod 100000007
#define ll long long
#define ini(x) scanf("%d",&x);
#define inl(x) scanf("%lld",&x);
#define ind(x) scanf("%lf",&x);
#define type double
using namespace std;
double inf=-1000000000;

struct Point{
  double x,y;
};

double dist(Point p1, Point p2){
  double x=p1.x-p2.x;
  x*=x;
  double y=p1.y-p2.y;
  y*=y;
  double distan= x+y;
  distan=sqrt(distan);
  return distan;
}


double solve(int N, double happiness[], Point points[]){
  int i,j,k;
  double dp[N];
  dp[N-1]=happiness[N-1];
  for(i=N-2;i>=0;i--){
    dp[i]=inf;
    for(j=i+1;j<N;j++){
      dp[i]=max(dp[i],happiness[i]-dist(points[i],points[j])+dp[j]);
    }
  }
  
  return dp[0];

}
int main(){
  int n;
  ini(n);
  Point points[n];
  double happiness[n];
  for(int i=0;i<n;i++){
    ind(points[i].x);
    ind(points[i].y);
    ind(happiness[i]);

  }
  printf("%0.6lf\n",solve(n,happiness,points));
}
