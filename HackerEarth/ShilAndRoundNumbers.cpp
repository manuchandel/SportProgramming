#include <bits/stdc++.h>
#define MAX 200001
using namespace std;

int bit[200001];
int update(int x,int y){
	int index=x+1;
	while(index<MAX){
		bit [index]+=y;
		index=index+(index&(-index));
	}
}

bool isround(long long N){
	if(N<0)
		return false;
	int digit[19];
	memset(digit,0,sizeof(digit));
	int i=0;
	
	while(N>0){
		digit[i]=N%10;
		i++;
		N/=10;
	}
	
	return (digit[0]==digit[i-1]);
}
int query(int x,int y){
	int index=y+1;
	int rans=0;
	while(index>0){
		rans+=bit[index];
		index=index-(index&(-index));
	}
	
	index=x;
	int lans=0;
	while(index>0){
		lans+=bit[index];
		index=index-(index&(-index));
		
	}
	return rans-lans;
}

int main()
{
    int N,Q,i;
    scanf("%d%d",&N,&Q);
    long long a[N];
    bool b[N];
    for(i=0;i<N;i++)
    	scanf("%lld",&a[i]);
    
    for(i=0;i<N;i++){
    	if(isround(a[i])){
    		update(i,1);
    		b[i]=1;
    	}else{
    		b[i]=0;
    	}
    }
	long long l,r,k;
    while(Q--){
    	scanf("%lld%lld%lld",&l,&r,&k);
    	if(l==1){
    		printf("%d\n",query((int)r-1,(int)k-1));
    	}else{
    		if(b[(int)r-1]){
    			update((int)r-1,-1);
    		}
    		
    		a[(int)r-1]=k;
    		if(isround(k)){
    			b[(int)r-1]=1;
    			update((int)r-1,1);
    		}else b[(int)r-1]=0;
    	}
    }
}
