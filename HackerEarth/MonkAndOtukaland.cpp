#include <bits/stdc++.h>
#define IN(L) scanf("%d",&L)
#define mod 3
#define ll long long
using namespace std;

struct Node{
	int l;
	int e;
	int r;
	bool c;
};
Node *tree=new Node[1000000];
int arr[200000];
void create(int l,int r,int i){
	if(l==r){
		tree[i].l=0;
		tree[i].e=0;
		tree[i].r=0;
		tree[i].c=false;
		return;
	}
	int lc=(i<<1)+1;
	int rc=(i<<1)+2;
	int mid=(l+r)>>1;
	create(l,mid,lc);
	create(mid+1,r,rc);
	tree[i].c=false;
	tree[i].l=tree[lc].l+tree[lc].r+tree[lc].e;
	tree[i].r=tree[rc].l+tree[rc].r+tree[rc].e;
	tree[i].e=arr[mid];
}

bool invert(bool c){
	if(c)
		return false;
	return true;
}
void update(int l,int r,int i,int x,int y){

	if(l==r)
		return;

	int lc=(i<<1)+1;
	int rc=(i<<1)+2;
	int mid=(l+r)>>1;
	if(tree[i].c==true){
		tree[i].e=1-tree[i].e;
		tree[i].l=(mid-l)-tree[i].l;
		tree[i].r=(r-mid-1)-tree[i].r;
		tree[i].c=false;
		tree[lc].c=invert(tree[lc].c);
		tree[rc].c=invert(tree[rc].c);
	}

	if(x==l and y==r){
		tree[i].e=1-tree[i].e;
		tree[i].l=(mid-l)-tree[i].l;
		tree[i].r=(r-mid-1)-tree[i].r;
		tree[i].c=false;
		tree[lc].c=invert(tree[lc].c);
		tree[rc].c=invert(tree[rc].c);

		return;
	}

	if(x>mid){
		update(mid+1,r,rc,x,y);
		tree[i].r=tree[rc].r+tree[rc].l+tree[rc].e;
		
	}else if(y<=mid){
		update(l,mid,lc,x,y);
		tree[i].l=tree[lc].l+tree[lc].r+tree[lc].e;
	}
	else{
		update(l,mid,lc,x,mid);
		update(mid+1,r,rc,mid+1,y);
		tree[i].l=tree[lc].l+tree[lc].r+tree[lc].e;
		tree[i].r=tree[rc].l+tree[rc].r+tree[rc].e;
		tree[i].e=1-tree[i].e;
	}

	

}




int query(int l,int r,int i,int x,int y){
	
	if(l==r)
		return 0;
	
	int lc=(i<<1)+1;
	int rc=(i<<1)+2;
	int mid=(l+r)>>1;

	if(tree[i].c==true){
		tree[i].e=1-tree[i].e;
		tree[i].l=(mid-l)-tree[i].l;
		tree[i].r=(r-mid-1)-tree[i].r;
		tree[i].c=false;
		tree[lc].c=invert(tree[lc].c);
		tree[rc].c=invert(tree[rc].c);
	}

	if(x==l && y==r)
		return tree[i].l+tree[i].r+tree[i].e;
	
	if(x>mid){
		return query(mid+1,r,rc,x,y);
	}else if(y<=mid){
		return query(l,mid,lc,x,y);
	}else{
		int a=query(l,mid,lc,x,mid);
		int b=query(mid+1,r,rc,mid+1,y);
		return tree[i].e+a+b;
	}
	
	
}

int main(){
int N,M;
	IN(N);IN(M);
	string s;
	cin>>s;
	for(int i=0;i<N;i++){
		if(s[i]=='>')
			arr[i]=1;
		else arr[i]=0;
	}
	create(0,N-1,0);
	while(M--){
		
		int a,b,c;
		IN(a);IN(b);IN(c);
		b-=1;c-=1;
		if(a==1){
			update(0,N-1,0,b,c);
		}else{
			if(c>b)
				printf("%d\n",c-b-query(0,N-1,0,b,c));
			else{
				printf("%d\n",query(0,N-1,0,c,b));
			}
		}
	}
		


}
