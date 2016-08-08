#include <bits/stdc++.h>
#define IN(L) scanf("%d",&L)
#define mod 3
#define ll long long
using namespace std;
struct Node{
	int leftmost;
	int rightmost;
	int present;
};
ll arr[100001];
void create(Node tree[],int l,int r,int i){
	if(l==r){
		tree[i].leftmost=tree[i].rightmost=tree[i].present=1;
		return;
	}
	int lc=(i<<1)+1;
	int rc=(i<<1)+2;
	int mid=(l+r)>>1;
	create(tree,l,mid,lc);
	create(tree,mid+1,r,rc);
	int bet=0;
	if(arr[mid+1]>arr[mid])
		bet=tree[lc].rightmost+tree[rc].leftmost;

	if(bet>=tree[lc].present and bet>=tree[rc].present){
		tree[i].present=bet;
		if(tree[lc].leftmost==mid-l+1){
			tree[i].leftmost=mid-l+1+tree[rc].leftmost;
		}else tree[i].leftmost=tree[lc].leftmost;
		if(tree[rc].rightmost==r-mid){
			tree[i].rightmost=tree[lc].rightmost+r-mid;
		}else tree[i].rightmost=tree[rc].rightmost;

	}
	else{
		tree[i].present=max(tree[lc].present,tree[rc].present);
		tree[i].leftmost=tree[lc].leftmost;
		tree[i].rightmost=tree[rc].rightmost;
	}

}

int query(Node tree[],int l,int r,int i,int x,int y){
	//cout<<x<<" "<<y<<" "<<l<<" "<<r<<endl;
	if(l==r){
		return tree[i].present;
	}
	int lc=(i<<1)+1;
	int rc=(i<<1)+2;
	int mid=(l+r)>>1;

	if(x==l && y==r)
		return tree[i].present;
	
	if(y<=mid)
		return query(tree,l,mid,lc,x,y);
	else if(x>mid)
		return query(tree,mid+1,r,rc,x,y);
	else{
		int a=query(tree,l,mid,lc,x,mid);
		int b=query(tree,mid+1,r,rc,mid+1,y);
		int c=0;
		if(arr[mid+1]>arr[mid]){
			c=min(tree[rc].leftmost,y-mid)+min(tree[lc].rightmost,mid-x+1);
		}
		return max(a,max(b,c));
	}
	
}
void update(Node tree[],int l,int r,int i,int x){
	if(l==r){
		return;
	}
		
	int lc=(i<<1)+1;
	int rc=(i<<1)+2;
	int mid=(l+r)>>1;
	
	if(x<=mid)
		update(tree,l,mid,lc,x);
	else  update(tree,mid+1,r,rc,x);
	
	int bet=0;
	if(arr[mid+1]>arr[mid])
		bet=tree[lc].rightmost+tree[rc].leftmost;

	if(bet>=tree[lc].present and bet>=tree[rc].present){
		tree[i].present=bet;
		if(tree[lc].leftmost==mid-l+1){
			tree[i].leftmost=mid-l+1+tree[rc].leftmost;
		}else tree[i].leftmost=tree[lc].leftmost;
		if(tree[rc].rightmost==r-mid){
			tree[i].rightmost=tree[lc].rightmost+r-mid;
		}else tree[i].rightmost=tree[rc].rightmost;

	}
	else{
		tree[i].present=max(tree[lc].present,tree[rc].present);
		tree[i].leftmost=tree[lc].leftmost;
		tree[i].rightmost=tree[rc].rightmost;
	}
	
}
int main(){
	int i,T;
	IN(T);
	Node tree[262144];
	while(T--){
		int N,Q;
		IN(N);
		IN(Q);
		for(i=0;i<N;i++)
			scanf("%lld",&arr[i]);

		
		int l,r,t;

		create(tree,0,N-1,0);

		for(i=0;i<Q;i++){
			scanf("%d%d%d",&t,&l,&r);

			if(t==0){
				l-=1;
				r-=1;
				printf("%d\n",query(tree,0,N-1,0,l,r) );
			}
			
			else {
				l-=1;;
				arr[l]+=r;
				update(tree,0,N-1,0,l);
				

			}
		}
	}


}
