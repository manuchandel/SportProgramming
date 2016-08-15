#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long

using namespace std;
ll arr[100000];
ll phi[100000];

double factors(ll l, ll r, int K){
	ll N=r-l+1;
	ll i,j;
	for(i=0;i<N;i++){
		arr[(int)i]=l+i;
		phi[(int)i]=l+i;
	}
	for(i=2;i*i<=r;i++){
		if(l%i==0)
			j=l;
		else{
			j=ceil((double)l/i)*i;
		}
		for(;j<=r;j+=i){
			if(arr[(int)(j-l)]%i==0){
				phi[(int)(j-l)]=phi[(int)(j-l)]-phi[(int)(j-l)]/i;
				while(arr[(int)(j-l)]%i==0){
					arr[(int)(j-l)]/=i;
				}
			}
		}
	}
	for(i=0;i<N;i++){
		if(arr[(int)i]>1)
			phi[(int)i]-=phi[(int)i]/arr[(int)i];
	}

	double prob=0;
	for(int k=0;k<N;k++){
		if(phi[k]%K==0)
			prob+=1;
	}
	prob/=(double)N;
	return prob;

}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--){
		ll l,r;
		int k;
		scanf("%lld%lld%d",&l,&r,&k);
		printf("%0.6lf\n",factors(l,r,k));
	}


	

}
