#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
#include <algorithm>
#define MAX 100000
#define ll long long
#define FOR(i,a,n) for(i=a;i<n;i++)
using namespace std;
struct Box{
  int x,y;
  int n;
};
struct D{
  int n;
  char arr[3];
};
Box *A=new Box[MAX];
vector<D> v;
D setDir(int a,string s){
  D d;
  d.n=a;
  d.arr[0]=s[0];
  d.arr[1]=s[1];
  d.arr[2]='\0';
  return d;
}
bool comparea(Box b1,Box b2){
  if(b1.x<b2.x)
    return 1;
  else if(b1.x>b2.x)
    return 0;
  if(b1.y>b2.y)
    return 1;
  return 0;
}
bool compareb(Box b1,Box b2){
  if(b1.y<b2.y)
    return 1;
  else if(b1.y>b2.y)
    return 0;
  if(b1.x>b2.x)
    return 1;
  return 0;
}
 
void foo1(int s,int e){
 
  if(s>e)
    return;
    int i,u,t;
    int p=s,q=s;
    for(i=s;i<=e;i++){
      if(A[i].x<=A[p].x)
        p=i;
      if(A[i].x>=A[q].x)
        q=i;
    }
    u=s;i=1;
    while(i<=e && A[i].y==A[s].y){
      if(A[i].x<A[u].x)
        u=i;
      i++;
    }
    t=e;i=e-1;
    while(i>=0 && A[i].y==A[e].y){
      if(A[i].x>A[t].x)
        t=i;
      i--;
    }
    if(A[p].x==A[s].x){
      v.clear();
      v.push_back(setDir(A[s].n,"NE"));
      return;
    }else if(A[p].x==A[u].x){
      v.clear();
      v.push_back(setDir(A[u].n,"NE"));
      return;
    }else if(A[p].x==A[e].x){
      v.clear();
      v.push_back(setDir(A[e].n,"SE"));
      return;
    }else if(A[q].x==A[s].x){
      v.clear();
      v.push_back(setDir(A[s].n,"NW"));
      return;
    }else if(A[q].x==A[e].x){
      v.clear();
      v.push_back(setDir(A[e].n,"SW"));
      return;
    }else if(A[q].x==A[t].x){
      v.clear();
      v.push_back(setDir(A[t].n,"SW"));
      return;
    }
}
void foo(int s,int e){
  if(s>e)
    return;
  int i,pmin,qmax;
  int p=s,q=s;
  for(i=s;i<=e;i++){
    if(A[i].y<=A[p].y)
      p=i;
    if(A[i].y>=A[q].y)
      q=i;
  }
  i=1;pmin=0;
  while(i<=e && A[i].x==A[s].x){
    if(A[i].y<A[pmin].y)
      pmin=i;
    i++;
  }
  i=e-1;qmax=e;
  while(i>=0 && A[i].x==A[e].x){
    if(A[i].y>A[qmax].y)
      qmax=i;
    i--;
  }
  if(A[p].y==A[s].y){
    v.push_back(setDir(A[s].n,"NE"));
    return;
  }else if(A[p].y==A[pmin].y){
    v.push_back(setDir(A[pmin].n,"NE"));
    return;
  }else if(A[p].y==A[e].y){
    v.push_back(setDir(A[e].n,"NW"));
    return;
  }else if(A[q].y==A[s].y){
    v.push_back(setDir(A[s].n,"SE"));
    return;
  }else if(A[q].y==A[e].y){
    v.push_back(setDir(A[e].n,"SW"));
    return;
  }else if(A[q].y==A[qmax].y){
    v.push_back(setDir(A[e].n,"SW"));
    return;
  }
  if(p<q){
    v.push_back(setDir(A[p].n,"NE"));
    v.push_back(setDir(A[q].n,"SW"));
    return;
  }else{
    v.push_back(setDir(A[p].n,"NW"));
    v.push_back(setDir(A[q].n,"SE"));
    return;
  }
}
void print(){
  int i,N=v.size();
  if(N==0)
    return;
  printf("%d\n",N);
  FOR(i,0,N)
    printf("%d %s\n",v[i].n,v[i].arr);
}
int main(){
  int i;
  int N,T;
  scanf("%d\n",&T);
  while(T--){
    scanf("%d",&N);
    FOR(i,0,N){
      scanf("%d%d",&A[i].x,&A[i].y);
      A[i].n=i+1;
    }
   sort(A,A+N,comparea);
   foo(0,N-1);
   sort(A,A+N,compareb);
   foo1(0,N-1);
   print();
   v.clear();
  }
}
