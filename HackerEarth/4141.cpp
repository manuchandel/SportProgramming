#include <bits/stdc++.h>
#define mod 1000003
#define mod2 1000000007
#define ll long long
#define max 1000001
#define base 101
using namespace std;


int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--){
	    int a,b,c,n;
	    scanf("%d%d%d%d",&a,&b,&c,&n);
	   	int prev=(a*10+b)%41;
	   	if(n==1)
	   		prev=a;
	   	int next;
	   	for(i=2;i<n;i++){
	   		next=(b*c+a)%10;
	   		prev=prev*10+next;
	   		prev%=41;
	   		a=b;
	   		b=next;
	   	}
	   	if(prev==0)
	   		printf("YES\n");
	   	else printf("NO\n");
	}

}
