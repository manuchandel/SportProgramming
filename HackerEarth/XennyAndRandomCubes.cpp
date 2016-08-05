#include <bits/stdc++.h>
#define IN(L) scanf("%d",&L)
#define mod 1000000007
using namespace std;

long long arr1[1025];
long long arr2[1025];
int arr[10][26];
int main(){
	int N,K,i,j,k;
	IN(N);IN(K);
	memset(arr,0,sizeof(arr));
	for(i=0;i<N;i++){
		for(j=0;j<6;j++){
			char c;
			scanf(" %c",&c);
			arr[i][c-'a']+=1;
		}
	}
	//cout<<"scanne all chars"<<endl;
	char str[11];
	scanf("%s",str);
	//cout<<"scanned string"<<endl;
	memset(arr1,0,sizeof(arr1));
	
	for(i=0;i<N;i++){
		arr1[(1<<i)]=arr[i][str[K-1]-'a'];
	}
	
	for(i=1;i<K;i++){ // for every character
		memset(arr2,0,sizeof(arr2));
		for(j=0;j<N;j++){	// for every dice
			int bit=(1<<j);	// keep this bit high
			for(k=0;k<1025;k++){	// all previous calculations
				//cout<<bit<<" "<<k<<" "<< (bit&k) <<endl;
				if((bit&k)==0){	// if bit is not high
					long long temp=(long long)arr[j][str[K-i-1]-'a']*(long long)arr1[k];
					temp%=mod;
					arr2[bit|k]+=temp;
					arr2[bit|k]%=mod;
				}
			}
		}
		memcpy(arr1,arr2,sizeof(arr2));
		
	}
	long long ans=0;
	for(i=0;i<1025;i++){
		ans+=arr1[i];
		ans%=mod;
	}
	printf("%lld\n",ans);
}
