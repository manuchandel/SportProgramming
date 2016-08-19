#include <bits/stdc++.h>
#define mod 1000000007

#define ll long long
using namespace std;
const ll inf=((ll)1<<60);
ll dp[50][1000];
ll Time[50][50];
ll cost[50][50];
int n;
struct Pair{
	int x,y;
};
Pair getmini(ll A[][1001],bool vis[][1001],int n){
	
	ll val=inf;
	Pair p;
	p.x=-1;
	p.y=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<1001;j++){
			if(!vis[i][j] and A[i][j]<val){
				val=A[i][j];
				p.x=i;
				p.y=j;
			}
		}
	}
	return p;
	
}
void djikstra(int n, int t){

	int i,j;
	ll A[50][1001];
	bool vis[50][1001];
	int T[50];
	ll c=inf;
	int totaltime=0;
	for(i=0;i<50;i++){
		for(j=0;j<1001;j++){
			vis[i][j]=false;
			A[i][j]=inf;
		}
	}
	A[0][0]=0;
	Pair p=getmini(A,vis,n);
	while(p.x>=0){

		vis[p.x][p.y]=true;
		i=p.x;
		for(j=0;j<n;j++){
			if(p.y+Time[i][j]<=t && A[i][p.y]+cost[i][j]<A[j][p.y+Time[i][j]]){
				A[j][p.y+Time[i][j]]=A[i][p.y]+cost[i][j];	
			}
		}

		p=getmini(A,vis,n);
	}
	int x;
	ll y=inf;
	for(i=0;i<=t;i++){
		if(A[n-1][i]<y){
			y=A[n-1][i];
			x=i;
		}
	}
	printf("%lld %d\n",y,x);
	

	


}
int main(){
	int toll,ti,i,j;

	scanf("%d %d",&toll,&ti);
	while(toll >0 and ti>0){
		for(i=0;i<toll;i++){
			for(j=0;j<toll;j++)
				scanf("%lld",&Time[i][j]);
		}
		for(i=0;i<toll;i++){
			for(j=0;j<toll;j++)
				scanf("%lld",&cost[i][j]);
		}

		djikstra(toll,ti);
		scanf("%d %d",&toll,&ti);
	}
}
