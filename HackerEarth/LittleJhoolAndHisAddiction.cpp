#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    int *a=new int[1000000];
    int N,i,K;
    scanf("%d",&T);
    while(T--){
    	scanf("%d%d",&N,&K);
    	for(i=0;i<N;i++){
    		scanf("%d",&a[i]);
    	}
    	sort(a,a+N);
    	for(i=0;i<N/2;i++)
    		a[i]+=a[N-i-1];
    	N=N>>1;
    	sort(a,a+N);
    	printf("%d\n",a[N-1]-a[0]);
    	if(a[N-1]-a[0]<K)
    		printf("Chick magnet Jhool!\n");
    	else if(a[N-1]-a[0]>K)
    		printf("No more girlfriends!\n");
    	else printf("Lucky chap!\n");
    }
    
}
