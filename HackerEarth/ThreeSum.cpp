#include <bits/stdc++.h>
#define IN(L) scanf("%d",&L)
#define MAX 1000001
using namespace std;
int main(){
	int i,j;
	int cubes[19];
	for(i=0;i<19;i++)
		cubes[i]=i*i*i;

	int a[500][19];
	int b[500];
	int Total[4001];
	int c[4001][500];
	memset(c,0,sizeof(c));
	int N,T;
	IN(T);
	while(T--){
		IN(N);
		for(i=0;i<N;i++)
			scanf("%d",&b[i]);
		for(i=0;i<N;i++){
			for(j=0;j<19;j++){
				a[i][j]=cubes[j]-b[i];
			}
		}
		for(i=0;i<N;i++){
			for(j=i+1;j<N;j++){
				Total[b[i]+b[j]]+=1;
				c[b[i]+b[j]][i]+=1;
				c[b[i]+b[j]][j]+=1;

			}
		}
		long long ans=0;
		for(i=0;i<N;i++){
			for(j=1;j<19;j++){
				if(a[i][j]>=0 && a[i][j]<4001){
					ans+=Total[a[i][j]]-c[a[i][j]][i];
				}
			}
		}
		ans=ans/3;
		long long t=N*(N-1)*(N-2);
		t/=6;

		double prob=(double)ans/(double)t;
		printf("%0.9lf\n",prob);
		memset(Total,0,sizeof(Total));
		for(i=0;i<N;i++){
			for(j=i+1;j<N;j++){
				c[b[i]+b[j]][i]=0;
				c[b[i]+b[j]][j]=0;

			}
		}
	}
}
