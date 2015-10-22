#include <cstdio>
#include <limits.h>
#define maxWeight 500
#define maxObjects 100
int *c=new int[maxObjects];
int *w=new int[maxObjects];
int *a=new int[maxWeight+1];
int *b=new int[maxWeight+1];
int *d=new int[maxWeight+1];
int *e=new int[maxWeight+1];
void swap(int **p,int **q){
	int *temp=*p;
	*p=*q;
	*q=temp;
}
int min(int a,int b){
	if(b>a)
		return a;
	return b;
}
int knapsack(int n,int W){
	int i,j,p,q;
	for(j=0;j<=W;j++){
		if(w[n-1]<=j){
			a[j]=c[n-1];
			b[j]=w[n-1];
		}
		else {
			a[j]=0;
			b[j]=0;
		}
	}
	for(i=n-2;i>=0;i--){
		for(j=0;j<=W;j++){
			if(w[i]>j){
				d[j]=a[j];
				e[j]=b[j];
			}
			else {
				p=c[i]+a[j-w[i]];
				q=a[j];
				if(p>q){
					d[j]=p;
					e[j]=w[i]+b[j-w[i]];
				}else if(q>p){
					d[j]=q;
					e[j]=b[j];
				}else{
					d[j]=p;
					e[j]=min(w[i]+b[j-w[i]],b[j]);
				}
			}
		}
		swap(&a,&d);
		swap(&b,&e);
	}
	printf("%d %d\n",b[W],a[W]);
	return a[W];
	
}
int main(){
	int n,i,W;
	scanf("%d%d",&W,&n);
	while(n&&W){	
		for(i=0;i<n;i++)
			scanf("%d%d",&w[i],&c[i]);
		knapsack(n,W);
		scanf("%d%d",&W,&n);
	}
}
