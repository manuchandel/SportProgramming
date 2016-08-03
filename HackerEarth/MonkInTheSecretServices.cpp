#include <bits/stdc++.h>
#define IN(X) scanf("%d",&X)
using namespace std;
int D[101][101];
int main(){
	int T,N,M,X,Y,C,S,A,H;
	int i,j,k;
	IN(T);
	while(T--){
		IN(N);IN(M);
		for(i=0;i<=N;i++)
			for(j=0;j<=N;j++)
				D[i][j]=9901;

		for(i=0;i<=N;i++)
			D[i][i]=0;
		while(M--){
			IN(X);IN(Y);IN(C);
			D[X][Y]=min(D[X][Y],C);
			D[Y][X]=D[X][Y];
		}

		for(k=1;k<=N;k++){
			for(i=1;i<=N;i++){
				for(j=1;j<=N;j++){
					D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
				}
			}
		}
		IN(S);IN(A);IN(H);
		int ans=INT_MIN;
		for(i=1;i<=N;i++){
			if(i!=S && i!=H && i!=A){
				ans=max(ans,D[S][i]+2*D[i][A]+D[i][H]);
			}
		}
		printf("%d\n",ans );
	}
}
