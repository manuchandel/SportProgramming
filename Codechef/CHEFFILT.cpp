#include <bits/stdc++.h>
#define mod 1000000007 
using namespace std;
// returns 2^n % mod
int util(int n){
	if(n<0)
		return 0;
	unsigned long long v=1;
	unsigned long long w=2;
	while(n>0){
		if(n&1)
			v=(v*w)%mod;
		n=n>>1;
		w=w*w;
		w%=mod;
	}
 
	return (int)v;
}
int main(){
	int T,N,i,j;
 
	string S;
	string filter;
	
	bitset<10> B;
	int A,count,freqcount, ans;
	int update[1024];
	int xr[1024];
	int freq[1024];
	
	scanf("%d",&T);
	while(T--){
		memset(xr,0,sizeof(int)*1024);
		memset(freq,0,sizeof(int)*1024);
		B.reset();
		cin>>S;
		for(i=0;i<10;i++)
			if(S[i]=='w')
				B[i]=true;
		A=(int)B.to_ulong();
		scanf("%d",&N);
		freqcount=N;
		while(N--){
			cin>>S;
			B.reset();
			for(i=0;i<10;i++)
				if(S[i]=='+')
					B[i]=true;
			i=(int)B.to_ulong();
			freq[i]=1;			
		}
 
		xr[0]=true;
		count=ans=0;
		for(i=0;i<1024;i++){
			if(freq[i]>0){
				memset(update,0,sizeof(int)*1024);
				for(j=0;j<1024;j++)
					if(xr[j])						
						update[i^j]=1;
 
				for(j=0;j<1024;j++)
					xr[j]+=update[j];
			}
		}
 
		for(i=0;i<1024;i++)
			if(xr[i]>0)
				count++;
 
		count=(int)log2(count);
		if(xr[A]>0)
			ans=util(freqcount-count);
		
		cout<<ans<<endl;
	}

