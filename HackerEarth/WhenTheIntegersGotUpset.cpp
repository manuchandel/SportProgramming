#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
int P[12];
int A[12];
int a[(1<<12)][12][12];
int len;
int solve(int i,int mask,int p,int q){

	if(i==len && mask==0)
		return 0;
	if(a[mask][p][q]!=-1)
		return a[mask][p][q];

	int x=mask;
	int sum=INT_MAX;
	int temp,j1,j2;
	int m=0;
	for(int j=0;j<len;j++){
		if(x&1){
			temp=A[j]^A[p];
			temp=temp^A[q];
			sum=min(sum,temp*P[i]+solve(i+1,(mask^(1<<j)),q,j));
		}
		x=x>>1;
	}
	a[mask][p][q]=sum;
	return sum;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&len);
		for(int i=0;i<len;i++){
			scanf("%d",&A[i]);
		}
		for(int i=0;i<len;i++){
			scanf("%d",&P[i]);
		}
		memset(a,-1,sizeof(a));
		int ans=INT_MAX;
		if(len<=2){
			ans=0;
		}
		else{
			for(int i=0;i<len;i++)
				for(int j=0;j<len;j++){
					if(j!=i){
						int mask=(1<<len)-1;
						mask=mask^(1<<j);
						mask=mask^(1<<i);
						ans=min(ans,solve(2,mask,i,j));
					}
				}
		}
		printf("%d\n",ans);
	}
}
