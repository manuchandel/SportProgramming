#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;
ll *tree=new ll[262150];
ll *arr=new ll[100000];
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void createSegtree(int start,int end,int segIndex){
	if(start==end){
		tree[segIndex]=arr[start];
		return;
	}
	int mid=start+(end-start)/2;
	int lc=2*segIndex+1, rc=2*segIndex+2;
	createSegtree(start,mid,lc);
	createSegtree(mid+1,end,rc);
	tree[segIndex]=tree[lc]+tree[rc];
}
ll query(int start,int end,int l,int r,int segIndex){
	if(start==l && end==r)
		return tree[segIndex];
	int mid=start+(end-start)/2;
	int lc=2*segIndex+1, rc=2*segIndex+2;
	if(r<=mid)
		return query(start,mid,l,r,lc);
	else if(l>mid)
		return query(mid+1,end,l,r,rc);
	else return query(start,mid,l,mid,lc)+query(mid+1,end,mid+1,r,rc);
}
ll modify(int start,int end,int l,int r,int segIndex){
	int mid=start+(end-start)/2;
	int lc=2*segIndex+1, rc=2*segIndex+2;
	if(tree[segIndex]==end-start+1)
		return tree[segIndex];
	if(start==end){
		tree[segIndex]=(int)sqrt(tree[segIndex]);
		return tree[segIndex];
	}
	if(r<=mid){
		tree[segIndex]=tree[rc]+modify(start,mid,l,r,lc);
		return tree[segIndex];
	}
	else if(l>mid){
		tree[segIndex]=tree[lc]+modify(mid+1,end,l,r,rc);
		return tree[segIndex];
	}
	else{
		tree[segIndex]=modify(start,mid,l,mid,lc)+modify(mid+1,end,mid+1,r,rc);
		return tree[segIndex];
	}

}
int main(){
	int N,M;
	int i,l,r,j,c=1;
	while(scanf("%d",&N)!=EOF){
		for(i=0;i<N;i++)
			scanf("%lld",&arr[i]);
		printf("Case #%d:\n",c);
		scanf("%d",&M);
		createSegtree(0,N-1,0);
		while(M--){
			scanf("%d%d%d",&j,&l,&r);
			if(l>r)
				swap(l,r);
			if(j==0)
				modify(0,N-1,l-1,r-1,0);
			else printf("%lld\n",query(0,N-1,l-1,r-1,0));
		}
	puts("");
	c++;
	}
	return 0;
}
