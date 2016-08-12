#include <bits/stdc++.h>
#define IN(L) scanf("%d",&L)
#define mod 1000000007
#define ll long long
using namespace std;

struct Node{
	int l;
	ll n;
	Node():l(0),n(0){}
};
Node tree[600000];
int arr[100000];
int freq[2000001];
void create(int l,int r,int i){
	if(l==r){
		tree[i].l=tree[i].n=0;
		return;
	}
	int lc=(i<<1)+1;
	int rc=(i<<1)+2;
	int mid=(l+r)>>1;
	create(l,mid,lc);
	create(mid+1,r,rc);
	tree[i].l=tree[i].n=0;
}
void update(int l,int r,int i,int x,Node node){

	if(l==r){
		if(tree[i].l==node.l){
			tree[i].n+= node.n;
			tree[i].n%=mod;
		}
		else if(tree[i].l<node.l){
			tree[i]=node;
		}
		return;

	}

	int lc=(i<<1)+1;
	int rc=(i<<1)+2;
	int mid=(l+r)>>1;

	if(x>mid)
		update(mid+1,r,rc,x,node);
	else update(l,mid,lc,x,node);

	int llc=tree[lc].l;
	int lrc=tree[rc].l;

	if(llc==lrc){
		tree[i].l=llc;
		tree[i].n=tree[lc].n+tree[rc].n;
		tree[i].n%=mod;
	}else if(llc>lrc){
		tree[i].l=llc;
		tree[i].n=tree[lc].n;
	}else{
		tree[i].l=lrc;
		tree[i].n=tree[rc].n;
	}

}




Node query(int l,int r,int i,int x,int y){
	
	if((l==r) or (x==l and y==r))
		return tree[i];
	int lc=(i<<1)+1;
	int rc=(i<<1)+2;
	int mid=(l+r)>>1;


	if(x>mid)
		return query(mid+1,r,rc,x,y);
	else if(y<=mid)
		return query(l,mid,lc,x,y);
	else{
		Node n1=query(l,mid,lc,x,mid);
		Node n2=query(mid+1,r,rc,mid+1,y);

		if(n1.l==n2.l){
			n1.n+=n2.n;
			n1.n%=mod;
			return n1;
		}
		if(n1.l>n2.l)
			return n1;
		return n2;
	}

	
}

int main(){
	int N,i;
	IN(N);

	for(i=0;i<N;i++)
		IN(arr[i]);

	int index=arr[N-1]+100000;
	Node node;
	node.l=1;
	node.n=1;
	update(0,200000,0,index,node);
	for(i=N-2;i>=0;i--){
		int n=arr[i];
		int x=0,y=-1;
		index=arr[i]+100000;
		if(arr[i]>0){
			x=0;
			y=0-(arr[i]+1)+100000;

		}else{
			y=200000;
			x=0-(arr[i]-1)+100000;
		}
		Node n1=query(0,200000,0,x,y);
		n1.l+=1;
		if(n1.n==0)
			n1.n=1;
			

		update(0,200000,0,index,n1);
	}
	printf("%d %lld\n",tree[0].l,tree[0].n);

}
