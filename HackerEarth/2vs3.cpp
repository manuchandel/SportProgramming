#include <bits/stdc++.h>
#define IN(L) scanf("%d",&L)
#define mod 3
#define ll long long
using namespace std;
int two[100001];

void create(int tree[],int l,int r,int i,string &s){
	if(l==r){
		tree[i]=s[l]-'0';
		return;
	}
	int lc=(i<<1)+1;
	int rc=(i<<1)+2;
	int mid=(l+r)>>1;
	create(tree,l,mid,lc,s);
	create(tree,mid+1,r,rc,s);

	tree[i]=two[r-mid]*tree[lc]+tree[rc];
	tree[i]%=3;

}

int query(int tree[],int l,int r,int i,int x,int y){
	//cout<<x<<" "<<y<<" "<<l<<" "<<r<<endl;
	if(l==r){
		return tree[i];
	}
	int lc=(i<<1)+1;
	int rc=(i<<1)+2;
	int mid=(l+r)>>1;

	if(x==l && y==r)
		return tree[i];
	
	if(y<=mid)
		return query(tree,l,mid,lc,x,y);
	else if(x>mid)
		return query(tree,mid+1,r,rc,x,y);
	else{
		int a=query(tree,l,mid,lc,x,mid);
		int b=query(tree,mid+1,r,rc,mid+1,y);
		//cout<<a<<" "<<b<<endl;
		return(two[y-mid]*a+b)%3;
	}
	
}
void update(int tree[],int l,int r,int i,int x){
	if(l==r){
		tree[i]=1;
		return;
	}
	int lc=(i<<1)+1;
	int rc=(i<<1)+2;
	int mid=(l+r)>>1;
	
	if(x<=mid)
		update(tree,l,mid,lc,x);
	else  update(tree,mid+1,r,rc,x);
	
	int a=tree[lc];
	int b=tree[rc];
	tree[i]=(two[r-mid]*a+b)%3;
	
}
int main(){
	int i;
	int tree[262144];
	two[0]=1;
	for(i=1;i<100001;i++){
		two[i]=2*two[i-1];
		two[i]%=3;
	}
	int N;
	cin>>N;
	string s;
	cin>>s;

	int Q;
	cin>>Q;
	int l,r,t;
	create(tree,0,s.length()-1,0,s);
	for(i=0;i<Q;i++){
		cin>>t;
		if(t==0){
			cin>>l>>r;
			printf("%d\n",query(tree,0,s.length()-1,0,l,r) );
		}
		else {
			cin>>l;
			if(s[l]=='0')
				update(tree,0,s.length()-1,0,l);
			s[l]='1';

		}
	}


}
