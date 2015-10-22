#include <cstdio>
#include <cstdlib>
#define N 50000
using namespace std;
int max(int a,int b){
	if(b>a)
		return b;
	return a;
}
int max(int a,int b,int c){
	int var=a;
	if(var<b)
		var=b;
	if(var<c)
		var=c;
	return var;
}
struct node{
	int leftsum,rightsum,midsum,total,best;
};
int arr[N];
node tree[131100];
void createSegtree(int start,int end,int segIndex){
	int mid=start+(end-start)/2;
	if(start==end){
		tree[segIndex].leftsum=tree[segIndex].rightsum=tree[segIndex].midsum=tree[segIndex].total=tree[segIndex].best=arr[start];
		return;
	}
	int lc=2*segIndex+1,rc=2*segIndex+2;
	createSegtree(start,mid,lc);
	createSegtree(mid+1,end,rc);
	tree[segIndex].leftsum=max(tree[lc].leftsum,tree[lc].total+tree[rc].leftsum);
	tree[segIndex].rightsum=max(tree[rc].rightsum,tree[rc].total+tree[lc].rightsum);
	tree[segIndex].midsum=tree[rc].leftsum+tree[lc].rightsum;
	tree[segIndex].total=tree[lc].total+tree[rc].total;
	tree[segIndex].best=max(tree[segIndex].leftsum,tree[segIndex].rightsum,tree[segIndex].midsum);
	tree[segIndex].best=max(tree[lc].best,tree[rc].best,tree[segIndex].best);
}
node query(int start,int end,int l,int r,int index){
	if(start==l && end==r)
		return tree[index];
	int mid=start+(end-start)/2;
	int lc=2*index+1,rc=2*index+2;
	if(r<=mid)
		return query(start,mid,l,r,lc);
	else if(l>mid)
		return query(mid+1,end,l,r,rc);
	else{
		node leftnode=query(start,mid,l,mid,lc);
		node rightnode=query(mid+1,end,mid+1,r,rc);
		node parent;
		parent.leftsum=max(leftnode.leftsum,leftnode.total+rightnode.leftsum);
		parent.rightsum=max(rightnode.rightsum,rightnode.total+leftnode.rightsum);
		parent.midsum=rightnode.leftsum+leftnode.rightsum;
		parent.total=leftnode.total+rightnode.total;
		parent.best=max(parent.leftsum,parent.rightsum,parent.midsum);
		parent.best=max(leftnode.best,rightnode.best,parent.best);
		return parent;
	}
}
int main(){
	int n,q,l,r,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&q);
	createSegtree(0,n-1,0);
	/*for(i=0;i<7;i++)
		printf("%d %d %d %d %d\n",tree[i].leftsum,tree[i].rightsum,tree[i].midsum,tree[i].total,tree[i].best );*/
	while(q--){
		scanf("%d%d",&l,&r);
		printf("%d\n",query(0,n-1,l-1,r-1,0).best);
	}
	
}
