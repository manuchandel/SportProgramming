#include <stdio.h>

int main()
{
    int T,N,i,A,B,count;
    int *H=malloc(sizeof(int)*1000001);
    scanf("%d",&T);
    while(T--){
    	count=0;
    	scanf("%d",&N);
    	memset(H,0,1000001*sizeof(int));
    	for(i=0;i<N;i++){
    		scanf("%d%d",&A,&B);
    		H[A]+=1;
    		if(H[B])
    			H[B]-=1;
    		else count++;
    	}
    	printf("%d\n",count);
    }
}
