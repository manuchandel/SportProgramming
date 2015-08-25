#include <cstdio>
#define TMAX 2057192
#define AMAX 1000000
#define FOR(a,b)  for(a=0;a<b;a++)
int *arr=new int[AMAX];
long long *tree=new long long[TMAX];
void createTree(int l,int r,int segIndex){
  if(l==r){
    tree[segIndex]=arr[l];
    return;
  }
  int mid=(l+r)>>1;
  createTree(l,mid,(segIndex<<1)+1);
  createTree(mid+1,r,(segIndex<<1)+2);
  tree[segIndex]=tree[(segIndex<<1)+1]+tree[(segIndex<<1)+2];
}
long long fetch(int l,int r,int i,int j,int segIndex){
  int mid=(l+r)>>1;
  if(l==i && r==j)
    return tree[segIndex];
  else if(i>mid)
    return fetch(mid+1,r,i,j,(segIndex<<1)+2);
  else if(j<=mid)
    return fetch(l,mid,i,j,(segIndex<<1)+1);
  else return fetch(l,mid,i,mid,(segIndex<<1)+1)+fetch(mid+1,r,mid+1,j,(segIndex<<1)+2);
}
void update(int l,int r,int i,int val,int segIndex){
  int mid=(l+r)>>1;
  tree[segIndex]+=(long long)val;
  if(l==r)
    return;
  if(i<=mid)
    update(l,mid,i,val,(segIndex<<1)+1);
  else update(mid+1,r,i,val,(segIndex<<1)+2);
}
int main()
{
  int i,j;
  int N;  //no of students
  int Q;  //no of queries
  char c;
  scanf("%d%d",&N,&Q);
  FOR(i,N)
    scanf("%d",&arr[i]);
  createTree(0,N-1,0);
  while(Q--){
    scanf(" %c",&c);
    scanf("%d%d",&i,&j);
    if(c=='S')
      printf("%lld\n",fetch(0,N-1,i,j,0));
    else if(c=='G')
      update(0,N-1,i,j,0);
    else update(0,N-1,i,0-j,0);
  }
}
