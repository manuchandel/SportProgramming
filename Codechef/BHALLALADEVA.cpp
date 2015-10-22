#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 100000
using namespace std;
int main(){
	int N,Q;
	int i,k;
	long long arr[MAX];
	long long sum[MAX];
	scanf("%d",&N);
	int ans=0;
	for(i=0;i<N;i++){
		scanf("%lld",&arr[i]);
		sum[i]=0;
	}
	sort(arr,arr+N);
	sum[0]=arr[0];
	for(i=1;i<N;i++)
		sum[i]=sum[i-1]+arr[i];
	scanf("%d",&Q);
	while(Q--){
		scanf("%d",&k);
		k=k+1;
		ans=ceil((double)N/k);
		printf("%lld\n",sum[ans-1]);
	}
}

