#include <bits/stdc++.h>
using namespace std;

int main()
{
   	priority_queue<int> pq;
    int N,M,i,X;
    long long ans=0;

	scanf("%d%d",&M,&N);
	for(i=0;i<M;i++){
		scanf("%d",&X);
		pq.push(X);
	}
    while(N-- && !pq.empty()){
    	X=pq.top();
    	pq.pop();
    	ans+=X;
    	X-=1;
    	if(X!=0)
    		pq.push(X);
    }
    printf("%lld\n",ans);
}
