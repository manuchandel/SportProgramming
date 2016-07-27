#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
void initialize(double **A,int rows,int columns){
	int i,j;
	for(i=0;i<rows;i++)
		for(j=0;j<columns;j++)
			A[i][j]=0.0;

	for(i=0;i<rows;i++)
		A[i][0]=1.0;
	
}
void print(double **A,int rows,int columns){
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++)
			printf("%06f ",A[i][j]);
		printf("\n");
	}
}
int main(){
	int i,j;
	double **A=new double *[MAX];
	for(i=0;i<MAX;i++)
		A[i]=new double [MAX];
	int T,X,Y,N,W,a,b;
	double p1,p2;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d%d",&X,&Y,&N,&W,&a,&b);
		p1=(double)a/100;
		p2=(double)b/100;

		initialize(A,N+1,W+1);
		int r=N+1;
		int c=W+1;

		for(i=1;i<r;i++)
			for(j=1;j<c;j++){
				double m=p1*A[i-1][max(0,j-X)]+(1-p1)*A[i-1][j];
				double n=p2*A[i-1][max(0,j-Y)]+(1-p2)*A[i-1][j];
				A[i][j]=max(m,n);
			}
		A[N][W]=100*A[N][W];
		printf("%.6f\n",A[N][W]);
	}

}
