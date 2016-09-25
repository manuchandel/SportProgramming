#include <bits/stdc++.h>
#define MAX 100009
#define mod 1000000007
#define ll long long
#define ini(x) scanf("%d",&x);
#define inl(x) scanf("%lld",&x);
#define type double
using namespace std;
ll dp[20][(1<<20)];
int g[20][20];
const ll inf=(ll)1<<60;
ll foo(int N){
  int i,j,k;
  memset(dp,0,sizeof(dp));
  vector<vector<int> >v;
  v.resize(N);
  int n=1<<N;
  for(i=1;i<n;i++){
    bitset<20> bits(i);
    v[(int)bits.count()-1].push_back(i);
  }
  for(i=0;i<N;i++){
    int mask=(1<<i);
    if(g[0][i]){
      dp[0][mask]=1;
    }
  }
  for(i=1;i<N;i++){
    for(j=0;j<v[i-1].size();j++){
      int courses_subset=v[i-1][j];

      for(k=0;k<N;k++){
        int course_mask=(1<<k);
        // ith student can take this course and this course is not already assigned to any other student        
        if(g[i][k] and (courses_subset&course_mask)==0){

            int new_subset=courses_subset|course_mask;
            dp[i][new_subset]+=dp[i-1][courses_subset];
        }
      }
    }
  }
  return dp[N-1][n-1];
}
int main(){
  int i,j,T,n;
  ini(T);
  while(T--){
    ini(n);
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        ini(g[i][j]);

    printf("%lld\n",foo(n) );
  }

 
}
