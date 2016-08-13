#include <bits/stdc++.h>
#define IN(L) scanf("%d",&L)
#define mod 1000000007
#define MAX 100001
#define ll long long
using namespace std;
int A[100000];
class Bit{
	public:

		long long *arr;
		Bit(){
			arr=new long long[MAX];
			memset(arr,0,sizeof(long long)*MAX);
			
		}
		void update(int x,long long y){
			int index=x+1;
			while(index<MAX){
				arr[index]+=y;
				arr[index]%=mod;
				index+=(index&(-index));
			}
		}
		long long query(int x, int y){
			int l=x;
			int r=y+1;
			int index=0;
			long long lans=0;
			long long rans=0;

			index=l;
			while(index>0){
				lans+=arr[index];
				lans%=mod;
				index=index-(index&(-index));
			}

			index=r;
			while(index>0){
				rans+=arr[index];
				rans%=mod;
				index=index-(index&(-index));
			}

			ll ans=rans-lans;
			if(ans<0)
				ans+=mod;

			return ans;
		}
};
int main(){
	
	int N,Q,i;
	
	Bit B[2];
	IN(N);
	for(i=0;i<N;i++)
		IN(A[i]);

	for(i=N-1;i>=0;i--){
		int x=A[i];
		long long left=B[1].query(0,x-1);
		long long right=B[0].query(x+1,100000);
		B[0].update(x,(left+1)%mod);
		B[1].update(x,(right+1)%mod);
	}
	ll ans=B[0].query(0,100000);
	ans+=B[1].query(0,100000);
	ans%=mod;
	ans-=N;
	if(ans<0)
		ans+=mod;
	ans-=N;
	if(ans<0)
		ans+=mod;
	printf("%lld\n",ans);
}
	
