#include <bits/stdc++.h>
#define MAX 65537
#define mod 100000007
#define ll long long
#define ini(x) scanf("%d",&x);
#define inl(x) scanf("%lld",&x);
#define ind(x) scanf("%lf",&x);
#define type double
using namespace std;
const double inf=1e9;
double dp[MAX];
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


double solve(Point points[], int n){
  int i,j,k,l;
  for(i=0;i<MAX;i++)
    dp[i]=inf;

  vector<vector<int> > v;
  
  int N=(1<<n);
  v.resize(n+1);
  for(i=0;i<N;i++){
    bitset<16> bits(i);
    v[bits.count()].push_back(i);
  }

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      int mask=(1<<i)|(1<<j);
      dp[mask]=dist(points[i],points[j]);
    }
  }

  for(i=2;i<n;i+=2){
    for(j=0;j<v[i].size();j++){
      int mask=v[i][j];
      for(k=0;k<n;k++){
        for(l=k+1;l<n;l++){
          int kmask=(1<<k);
          int lmask=(1<<l);
          int pairmask=kmask|lmask;
          if((pairmask&mask)==0){
            int newmask=pairmask|mask;
            dp[newmask]=min(dp[newmask],dp[mask]+dist(points[k],points[l]));
          }
        }
      }
    }
  }
  return dp[N-1];
}
int main(){
  int n;
  ini(n);
  n*=2;
  Point points[16];
  for(int i=0;i<n;i++){
    ind(points[i].x);
    ind(points[i].y);
  }
  printf("%0.6lf\n",solve(points,n));
}
