#include <cstdio>
using namespace std;
int *segtree=new int[262150];
bool *lazy=new bool[262150];
inline void fastRead_int(int *a)
{
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}
void createSegTree(int start,int end,int segIndex){
	int mid=start+end;
	mid=mid>>1;
	if(start==end){
		segtree[segIndex]=0;
		lazy[segIndex]=false;
		return;
	}
	int lc=(segIndex<<1)+1,rc=(segIndex<<1)+2;
	segtree[segIndex]=0;
	createSegTree(start,mid,lc);
	createSegTree(mid+1,end,rc);
	lazy[segIndex]=false;
}
void update(int start,int end,int l,int r,int segIndex){
	int mid=start+end;
	mid=mid>>1;
	int lc=(segIndex<<1)+1,rc=(segIndex<<1)+2;
	//printf("%d %d %d %d %d %d\n",lc,rc,segIndex,start,end,mid );

	if(start==l && end==r){
		segtree[segIndex]=r-l+1-segtree[segIndex];
		if(start!=end)
			lazy[segIndex]=!lazy[segIndex];
		return;
	}
	if(lazy[segIndex]==true){
		update(start,mid,start,mid,lc);
		update(mid+1,end,mid+1,end,rc);
		lazy[segIndex]=false;
	}
	if(l>mid) update(mid+1,end,l,r,rc);
	else if(r<=mid) update(start,mid,l,r,lc);
	else{
		update(start,mid,l,mid,lc);
		update(mid+1,end,mid+1,r,rc);
	}
	segtree[segIndex]=segtree[lc]+segtree[rc];
}
int query(int start,int end,int l,int r,int segIndex){
	int mid=start+end;
	mid=mid>>1;
	int lc=(segIndex<<1)+1,rc=(segIndex<<1)+2;
	if(start==l && end==r)
		return segtree[segIndex];
	if(lazy[segIndex]==true){
		lazy[segIndex]=false;
		update(start,mid,start,mid,lc);
		update(mid+1,end,mid+1,end,rc);
	}
	if(l>mid)
		return query(mid+1,end,l,r,rc);
	else if(r<=mid)
		return query(start,mid,l,r,lc);
	else return query(start,mid,l,mid,lc)+query(mid+1,end,mid+1,r,rc);
}
void print(int N){
	for(int i=0;i<N;i++)
		printf("%d %d\n",i,segtree[i]);
}
int main(){
	int N,Q,i,l,r;
	fastRead_int(&N);
	fastRead_int(&Q);
	createSegTree(0,N-1,0);
	while(Q--){
		fastRead_int(&i);
		fastRead_int(&l);
		fastRead_int(&r);
		if(i==0)
			update(0,N-1,l-1,r-1,0);
		else printf("%d\n",query(0,N-1,l-1,r-1,0));
		//print(9);
	}
}
