#include <bits/stdc++.h>
#define mod 1000003
#define mod2 1000000007
#define ll long long
#define max 10000001
#define base 101
using namespace std;

int *arr=new int[max];
int *phi=new int[max];
void findFactors(){
	int i,j;
	for(i=0;i<max;i++){
		phi[i]=i;
		arr[i]=i;
	}

	for(i=2;i*i<max;i++){
		for(j=i*i;j<max;j+=i){
			if(arr[j]%i==0){
				int x=0;
				while(arr[j]%i==0){
					x+=1;
					arr[j]/=i;
				}
				phi[j]=phi[j]-phi[j]/i;
			}
		}
	}
	for(i=1;i<max;i++){
		if(arr[i]!=1)
			phi[i]=phi[i]-phi[i]/arr[i];
	}
}



int main()
{
	int T,i;
	ll *ans=new ll[max];
	ans[0]=0;
	findFactors();
	for (i = 1; i < max; i++){
		ans[i]=ans[i-1]+phi[i];
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&i);
		printf("%lld\n",ans[i] );
	}


	

}
