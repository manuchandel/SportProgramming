#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,T,k;
    long long candies;
	long long ans;
    scanf("%d",&T);
    while(T--){
    	ans=0;
    	priority_queue<long long> pq;
    	scanf("%d%d",&n,&k);
    	while(n--){
    		scanf("%lld",&candies);
    		pq.push(candies);
    	}
    	while(k--){
    		candies=pq.top();
    		ans+=candies;
    		pq.pop();
    		candies=candies>>1;
    		pq.push(candies);
    	}
    	printf("%lld\n",ans);
    }
}

