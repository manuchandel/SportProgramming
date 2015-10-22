#include <stdio.h>

int main()
{
   int T,m,n,i,p,q;
   int A[500000];
   int B[500000];
   scanf("%d",&T);
   while(T--){
   	scanf("%d%d",&m,&n);
   	for(i=0;i<m;i++)
   		scanf("%d",&A[i]);
   	for(i=0;i<n;i++)
   		scanf("%d",&B[i]);
   	p=0;q=0;
   	while(p<m && q<n){
   		if(A[p]>B[q]){
   			printf("%d ",A[p]);
   			p++;
   		}else{
   			printf("%d ",B[q]);
   			q++;
   		}
   	}
   	while(p<m){
   		printf("%d ",A[p]);
   		p++;
   	}
   	while(q<n){
   		printf("%d ",B[q]);
   		q++;
   	}
   	printf("\n");   	
   }
}

