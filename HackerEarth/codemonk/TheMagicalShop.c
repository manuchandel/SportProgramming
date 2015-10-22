#include <stdio.h>
#include <string.h>
int main()
{
	int n,i;
    long long a,b,ans,temp;
    char buffer[100001];
    scanf("%lld%lld",&a,&b);
    scanf("%s",buffer);
    n=strlen(buffer);
    if(buffer[0]=='1')
    	ans=a%b;
    else ans=0;
    temp=a%b;
    for(i=1;i<n;i++){
    	temp=(temp*temp);    	
    	temp%=b;
    	if(buffer[i]=='1'){
    		ans+=temp;
    		ans%=b;
    	}
    }
    printf("%lld\n",ans);
}

