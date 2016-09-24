#include <bits/stdc++.h>
#define mod 1000000007
#define max 2100000
#define ll long long
using namespace std;
struct Node{
	int n;
	int l;
	int r;
};

Node *trie=new Node[max];
int A[100000];
int next;
int createNode(){
	next+=1;
	return next-1;
	
}

void insert(int a){
	bitset<20> bit(a);
	int root=0,i;
	for(i=19;i>=0;i--){
		if(bit[i]==1){
			if(trie[root].r==-1)
				trie[root].r=createNode();
			
			trie[root].n+=1;
			root=trie[root].r;
		}else{
			if(trie[root].l==-1)
				trie[root].l=createNode();
			
			trie[root].n+=1;
			root=trie[root].l;
		}
	}
	trie[root].n+=1;

}
ll find(bitset<20> &k,int l){
	bitset<20> bit(l);
	ll ans=0;
	int root=0,i;
	for(i=19;i>=0;i--){
		if(root==-1)
			return ans;
		if(bit[i]==1 && k[i]==1){
			if(trie[root].r!=-1)
				ans+=trie[trie[root].r].n;
			root=trie[root].l;
		}else if(bit[i]==1 && k[i]==0){
			root=trie[root].r;
		}else if(bit[i]==0 and k[i]==1){
			if(trie[root].l!=-1)
				ans+=trie[trie[root].l].n;
			root=trie[root].r;
		}else{
			root=trie[root].l;
		}
	}
	return ans;

}
int main(){
	int t,i;

	scanf("%d",&t);
	for(i=0;i<max;i++){
		trie[i].n=0;
		trie[i].l=-1;
		trie[i].r=-1;
	}
	next=1;
	while(t--){

		for(i=0;i<next;i++){
			trie[i].n=0;
			trie[i].l=-1;
			trie[i].r=-1;
		}
		next=1;
		int n,k;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++){
			scanf("%d",&A[i]);
		}
		int prev=0;
		ll ans=0;
		bitset<20> bit(k);
		insert(0);
		for(i=0;i<n;i++){
			int now=prev^A[i];
			ans+=find(bit,now);
			//cout<<ans<<endl;
			insert(now);
			prev=now;
		}
		printf("%lld\n",ans);
	}
}
