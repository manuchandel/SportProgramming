#include <bits/stdc++.h>
#define mod 1000000007
#define max 200002
#define ll long long
using namespace std;
struct st{
	ll v;
	int i;
};
ll bit[max];
st arr[max];
ll a[max];

ll query(int l, int r){
	ll lans=0;
	ll rans=0;
	int index=l;
	while(index>0){
		lans+=bit[index];
		index=index - (index&(-index));
	}

	index=r+1;
	while(index>0){
		rans+=bit[index];
		index=index- (index&(-index));
	}
	return rans-lans;
}
void update(int i,ll l){
	int index=i+1;
	//cout<<index<<endl;
	while(index<max){
		//cout<<index<<endl;
		bit[index]+=l;
		index=index+(index&(-index));
	}
}
bool comp(st p, st q){
	return p.v<q.v;
}
int main(){
	int t,i,n;
	scanf("%d",&t);
	
	while(t--){
		memset(bit,0,sizeof(ll)*max);
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
			arr[i].v=a[i];
			arr[i].i=i;
		}
		sort(arr,arr+n,comp);
		for(i=0;i<n;i++){
			a[arr[i].i]=i+1;
		}
		ll ans=0;

		update(a[n-1],1);
		for(i=n-2;i>=0;i--){
			ans+=query(0,a[i]-1);
			update(a[i],1);
		}
		printf("%lld\n",ans);

	}
}
