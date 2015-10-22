#include <stdio.h>
#include <vector>
#include <cmath>
#include <time.h>
#include <cstdlib>
#include <tr1/unordered_map>
#include <algorithm>
#define maxN 1000000
#define ll long long
using namespace std;
std::tr1::unordered_map<int, vector<ll> > query;

ll *factors=new ll[maxN];
ll *numbers=new ll[maxN];
void mappingTheFactors(){
	ll i,j;
	ll number;
	for(i=1;i<maxN;i++){
		number=i*i;
		query[factors[i]].push_back(number);
	}
}

ll logBaseN(ll &a,ll N){
	ll count=0;
	while(a%N==0){
		count++;
		a/=N;
	}
	return count;
}
/* function to implement modified sieve to find factors*/
void sieve(){
	bool a[maxN];
	ll i,j;
	for(i=0;i<maxN;i++){
		a[i]=false;
		numbers[i]=i;
		factors[i]=1;
	}
	for(i=2;i<maxN;i++){
		if(a[i]==false){
			for(j=i*2;j<maxN;j+=i){
				a[j]=true;
				factors[j]=factors[j]*(logBaseN(numbers[j],i)*2+1);
			}
			factors[i]=3;
		}
	}
}
int main(){
	//clock_t start=clock(),end;
	int t,k;
	ll ans,low,high;
	sieve();
	mappingTheFactors();
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld%lld",&k,&low,&high);
		if(query[k].size()==0)
			printf("%d\n",0);
		else{
			ans=upper_bound(query[k].begin(),query[k].end(),high)-lower_bound(query[k].begin(),query[k].end(),low);
			printf("%lld\n",ans);
		}
	}
}
