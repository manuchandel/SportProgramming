#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=((ll)1<<60);

ll dp[10001][100];
struct Pairs{
	int x,y;
};

int N;
unordered_map<int,vector<Pairs> > roads[100];
vector<Pairs> zero;
vector<int> zerolen;
int geti(int A[],bool vis[],int n){
	int index=-1;
	int val=(1<<28);
	int i;
	for(i=0;i<n;i++){
		if(!vis[i] && A[i]<val){
			index=i;
			val=A[i];
		}
	}
	return index;
}
void djikstra(int N){
	int i,j,l;
	int A[N];
	bool vis[N];
	int infi=(1<<28);
	for(i=0;i<N;i++){
		A[i]=infi;
		vis[i]=false;
	}
	A[0]=0;
	i=geti(A,vis,N);
	while(i>=0){
		vis[i]=1;
		for(j=0;j<N;j++){
			if(roads[i].find(j)!=roads[i].end()){
				int n=roads[i][j].size();
				for(l=0;l<n;l++){
					if(roads[i][j][l].x==0 && A[j]>A[i]+roads[i][j][l].y){
						A[j]=A[i]+roads[i][j][l].y;
					}
				}
			}
		}
		i=geti(A,vis,N);
	}
	for(i=0;i<N;i++){
		if(A[i]!=infi)
			dp[0][i]=A[i];
	}

}
ll bottomup(int T,int N){

	int i,j,k,l;

	for(i=0;i<10001;i++)
		for(j=0;j<100;j++)
			dp[i][j]=inf;

	djikstra(N);

	for(i=1;i<=T;i++){
		for(j=0;j<N;j++){
			dp[i][j]=dp[i-1][j];
			for(k=0;k<N;k++){
				if(roads[k].find(j)!=roads[k].end()){
					int n=roads[k][j].size();
					for(l=0;l<n;l++){
						int toll=roads[k][j][l].x;
						int len=roads[k][j][l].y;

						if(i-toll>=0)
							dp[i][j]=min(dp[i][j],(ll)len+dp[i-toll][k]);
					}
				}			
			}			
		}
		for(j=0;j<zero.size();j++)
			dp[i][zero[j].y]=min(dp[i][zero[j].y],dp[i][zero[j].x]+(ll)zerolen[j]);
		

	}
	ll ans=inf;
	for(i=0;i<=T;i++)
		ans=min(ans,dp[i][N-1]);
	return ans;

}
int main(){
	int T,K,R,i,s,d,t,l;
	scanf("%d",&T);
	while(T--){
		
		scanf("%d",&K);
		scanf("%d",&N);
		scanf("%d",&R);

		for(i=0;i<R;i++){
			scanf("%d%d%d%d",&s,&d,&l,&t);
			Pairs p;
			p.x=t;
			p.y=l;
			if(s!=d)
				roads[s-1][d-1].push_back(p);
			if(t==0){
				p.x=s-1;
				p.y=d-1;

				zero.push_back(p);
				zerolen.push_back(l);
			}
		}
		ll ans=bottomup(K,N);
		if(ans==inf)
			printf("-1\n");
		else printf("%lld\n",ans);
		for(i=0;i<100;i++)
			roads[i].clear();
		zero.clear();
		zerolen.clear();
	}
}
