#include <stdio.h>
#define N 2001
#define maxN 1000000
using namespace std;
int max(int a,int b){
	if(a>b)
		return a;
	return b;
}
int freq[N];
int main(){
	int t,n,j,i,temp,maxfreq,maxNo=-10000,maxfreqno=-10000;
	for(i=0;i<2001;i++)
			freq[i]=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		maxfreq=0;
		maxfreqno=0;
		for(i=0;i<=2000;i++)
			freq[i]=0;
		for(i=0;i<n;i++){
			scanf("%d",&temp);
			temp+=1000;
			freq[temp]++;
			if(freq[temp]>maxfreq){
				maxfreq=freq[temp];
				maxfreqno=temp-1000;
			}
		}
		if(maxfreq>(int)n/2)
			printf("YES %d\n",maxfreqno);
		else printf("NO\n");
	}
}
