#include <bits/stdc++.h>
#define ll long long
#define MAX 300001
#define mod 1000000007
using namespace std;
bool isprimeaux(ll p){
    if(p==0 or p==1)
        return false;
    ll a=rand()%(p-2)+2;
    ll b=p-1;
    ll x=1;
    ll y=a%p;
    while(b>0){
        if(b&1){
            x=x*y;
            x%=p;
        }
        b=b>>1;
        y=y*y;
        y%=p;
    }
    if(x==1)
        return true;
    return false;
}
bool isprime(ll p){
    return (isprimeaux(p)&&isprimeaux(p)&&isprimeaux(p));
}
int main(){
    srand(time(0));
    int i,j,t;
    int a[1000001];
    bool p[1001];
    for(i=0;i<1001;i++)
        p[i]=true;
    memset(a,0,sizeof(a));
    a[0]=a[1]=0;
    p[0]=p[1]=false;
    for(i=2;i<34;i++){
        if(p[i]){
        for(j=i*i;j<=1000;j+=i){
            p[j]=0;
        }
        }
    }
    a[2]=1;
    for(i=2;i<=1000;i++){
        if(p[i]){
            ll divide=i-1;
            ll power=i*i;
            ll number=i;
            while(number<1000001){
                ll pr=power-1;
                pr/=divide;
            
                if(isprime(pr)){
        
                    a[(int)number]=1;
                }
                power=power*i;
                number=number*i;
            }
        }
    }
    for(i=2;i<=1000000;i++){
        a[i]+=a[i-1];
    }
    scanf("%d",&t);
    while(t--){
        int a1,b;
        scanf("%d%d",&a1,&b);
        printf("%d\n",a[b]-a[a1-1] );
    }
}
