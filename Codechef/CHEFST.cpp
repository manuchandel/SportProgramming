#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    long long n1,n2,m;
    long long mini;
    long long ans;
    long long sum;
    while(T--){
        ans=0;
        scanf("%lld%lld%lld",&n1,&n2,&m);
        ans=max(n1,n2)-min(n1,n2);
        mini=min(n1,n2);
        sum=m*(m+1);
        sum=sum>>1;
        ans+=2*max(mini-sum,(long long)0);
        printf("%lld\n",ans);
    }
}