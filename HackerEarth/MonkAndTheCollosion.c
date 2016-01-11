#include <stdio.h>

int main()
{
    int T,N,X[10],i,temp,sum;
    scanf("%d",&T);
    while(T--){
    	sum=0;
    	scanf("%d",&N);
    	memset(X,0,sizeof(X));
    	for(i=0;i<N;i++){
    		scanf("%d",&temp);
    		X[temp%10]+=1;
    	}
    	for(i=0;i<10;i++){
    		if(X[i]>0)
    			sum+=(X[i]-1);
    	}
    	printf("%d\n",sum);
    }
}

