/*
author Manu
algorithm : BIT
*/

#include <bits/stdc++.h>
#define MAX 10001
#define ll long long
using namespace std;

ll bit[MAX];
void update(int i, ll x){
    int index=i+1;
    while(index<=MAX){
        bit[index]+=x;
        index=index+(index&(-index));
    }
}
ll query(int x){
    ll ans=0;
    int index=x+1;
    while(index>0){
        ans+=bit[index];
        index=index-(index&(-index));
    }
    return ans;
}

int main(){
    int t,i,j,T;
    scanf("%d",&T);

    for(t=0;t<T;t++){
        memset(bit,0,sizeof(bit));
        int N,U,Q;
        scanf("%d%d",&N,&U);
        for(i=0;i<U;i++){
            int l,r,v;
            scanf("%d%d%d",&l,&r,&v);
            update(l,v);
            update(r+1,-v);
        }
        scanf("%d",&Q);
        while(Q--){
            scanf("%d",&i);
            printf("%lld\n",query(i));
        }        
    }
}
