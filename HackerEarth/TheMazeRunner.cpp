#include <bits/stdc++.h>
using namespace std;
struct Point{
	int x;
	int y;
};
long double dist(Point p1, Point p2){
	return (long double)sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
bool check(Point p1,Point p2,Point p3,int H){

	double slope=(double)(p2.y-p1.y)/(double)(p2.x-p1.x);

	double y=(double)p2.y+slope*(double)(p3.x-p2.x);
	//printf("%d %d %d %d %f\n",p1.x,p1.y,p2.x,p2.y,y);
	if(y<=(double)p3.y+H && y>=(double)p3.y)
		return true;
	return false;
}
int main(){

	int N,H,i,k,j;
	scanf("%d",&N);
	Point up[N+1];
	Point dwn[N+1];

	for(i=0;i<=N;i++)
		scanf("%d%d",&dwn[i].x,&dwn[i].y);
	
	scanf("%d",&H);

	for(i=0;i<=N;i++){
		up[i].x=dwn[i].x;
		up[i].y=dwn[i].y+H;
	}

	long double dp[N+1][2];
	for(i=0;i<=N;i++)
		dp[i][0]=dp[i][1]=1e8;

	int maxy=dwn[N].y;
	int miny=up[N].y;
	for(i=N;i>=0;i--){
		dp[i][0]=1e8;

		// direct distance
		if(dwn[i].y>=maxy && dwn[i].y<=miny){
			dp[i][0]=min(dp[i][0],(long double)dwn[N].x-(long double)dwn[i].x);
		}
		//cout<<i <<" direct "<<dp[i][0]<<endl;
		//other distance from down segments
		for(j=i+1;j<=N;j++){
			bool flag=true;
			for(k=i+1;k<=j && flag;k++){
				flag=flag&&check(dwn[i],dwn[j],dwn[k],H);
			}

			if(flag)
				dp[i][0]=min(dp[i][0],dist(dwn[i],dwn[j])+dp[j][0]);
		}
		//cout<<i <<" down "<<dp[i][0]<<endl;
		//other distance from up segments
		for(j=i+1;j<=N;j++){
			bool flag=true;
			for(k=i+1;k<=j && flag;k++){
				flag=flag&&check(dwn[i],up[j],dwn[k],H);
			}
			//cout<<i <<" down up "<<flag<<" "<<j<<endl;
			if(flag)
				dp[i][0]=min(dp[i][0],dist(dwn[i],up[j])+dp[j][1]);
		}
		//cout<<i <<" up "<<dp[i][0]<<endl;

		dp[i][1]=1e8;

		// direct distance
		if(up[i].y>=maxy && up[i].y<=miny){
			dp[i][1]=min(dp[i][1],(long double)up[N].x-up[i].x);
		}

		//other distance from down segments
		for(j=i+1;j<=N;j++){
			bool flag=true;
			for(k=i+1;k<=j && flag;k++){
				flag=flag&&check(up[i],dwn[j],dwn[k],H);
			}

			if(flag)
				dp[i][1]=min(dp[i][1],dist(up[i],dwn[j])+dp[j][0]);
		}
		//other distance from up segments
		for(j=i+1;j<=N;j++){
			bool flag=true;
			for(k=i+1;k<=j && flag;k++){
				flag=flag&&check(up[i],up[j],dwn[k],H);
			}

			if(flag)
				dp[i][1]=min(dp[i][1],dist(up[i],up[j])+dp[j][1]);
		}
		
		maxy=max(maxy,dwn[i].y);
		miny=min(miny,up[i].y);
	}

	long double direct=1e8;
	if(miny>=maxy)
		direct=(long double)dwn[N].x-(long double)dwn[0].x;

	long double ans=direct;
	maxy=dwn[0].y;
	miny=up[0].y;
	for(i=0;i<=N;i++){
		long double direct_dist=1e8;
		if(dwn[i].y>=maxy && dwn[i].y<=miny){
			direct_dist=dwn[i].x-dwn[0].x;
		}
		ans=min(ans,direct_dist+dp[i][0]);
		direct_dist=1e8;
		if(up[i].y>=maxy && up[i].y<=miny){
			direct_dist=up[i].x-up[0].x;
		}
		ans=min(ans,direct_dist+dp[i][1]);
		maxy=max(maxy,dwn[i].y);
		miny=min(miny,up[i].y);
	}
	
	cout.precision(10);
	cout<<fixed<<ans<<endl;
}
