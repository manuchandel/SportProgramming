#include <bits/stdc++.h>
#define MAX 100001
#define ll long long
using namespace std;

void update(int i, ll x, ll bit[]){
    int index=i+1;
    while(index<=MAX){
        bit[index]+=x;
        index=index+(index&(-index));
    }
}
ll query(int x,ll bit[]){
    ll ans=0;
    int index=x+1;
    while(index>0){
        ans+=bit[index];
        index=index-(index&(-index));
    }
    return ans;
}

void updaterange(int l, int r, ll x, ll bit1[], ll bit2[]){

    update(l,x,bit1);
    update(r+1,-x,bit1);
    update(l,x*(l-1),bit2);
    update(r+1,-r*x,bit2);
}

ll queryrange(int l, int r, ll bit1[], ll bit2[]){

    
    ll rans=query(r,bit1)*r-query(r,bit2);
    if(l==0)
        return rans;
    ll lans=query(l-1,bit1)*(l-1)-query(l-1,bit2);
    
    return rans-lans;
}
int main(){
    ll bit1[MAX];
    ll bit2[MAX];
    int t,i,j,T,p,q;
    ll v;
    scanf("%d",&T);

    while(T--){
        memset(bit1,0,sizeof(bit1));
        memset(bit2,0,sizeof(bit2));
        int n,c;
        scanf("%d%d",&n,&c);
        while(c--){
            scanf("%d%d%d",&t,&p,&q);
            if(t==0){
                scanf("%lld",&v);
                updaterange(p-1,q-1,v,bit1,bit2);
            }
            else{
                printf("%lld\n",queryrange(p-1,q-1,bit1,bit2));
            }
        }

    }
}
