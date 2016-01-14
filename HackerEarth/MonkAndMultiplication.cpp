#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;
    int N,i,t1,t2,t3;
 
    scanf("%d",&N);
       int a[N];
    for(i=0;i<N;i++)
    	scanf("%d",&a[i]);
    long long ans=1;
    for(i=0;i<min(N,2);i++){
    	printf("-1\n");
    	pq.push(a[i]);
    }
    for(i=2;i<N;i++){
    	pq.push(a[i]);
    	t1=pq.top();
    	pq.pop();
    	t2=pq.top();
    	pq.pop();
    	t3=pq.top();
    	pq.pop();
    	ans=t1*t2*t3;
    	printf("%lld\n",ans);
    	pq.push(t1);
    	pq.push(t2);
    	pq.push(t3);
    	
    }
}
