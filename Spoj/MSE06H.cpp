/*
  Author : Manu
  Algorithm : count inversions. BIT

*/

#include <bits/stdc++.h>
#define MAX 1001
#define ll long long
using namespace std;

ll bit[MAX];
int highway[1001][1001];
void update(int i, ll x){
    int index=i+1;
    while(index<=MAX){
        bit[index]+=x;
        index=index+(index&(-index));
    }
}
ll query(int x,int y){
    ll lans=0;
    ll rans=0;
    int index=x;
    while(index>0){
        lans+=bit[index];
        index=index-(index&(-index));
    }

    index=y+1;
    while(index>0){
        rans+=bit[index];
        index=index-(index&(-index));
    }
    return rans-lans;
}

int main(){
    int t,i,j,T;
    scanf("%d",&T);

    for(t=0;t<T;t++){
        memset(bit,0,sizeof(bit));
        memset(highway,0,sizeof(highway));

        int N,M,K,x,y,p;
        scanf("%d%d%d",&N,&M,&K);
        for(i=0;i<K;i++){
            scanf("%d%d",&x,&y);
            p=highway[x][0];
            highway[x][p+1]=y;
            p++;
            highway[x][0]=p;
        }
        ll inv=0;
        for(i=N;i>=0;i--){
            int n=highway[i][0];
            for(j=1;j<=n;j++)
                inv+=query(0,highway[i][j]-1);
            for(j=1;j<=n;j++)
                update(highway[i][j],1);
        }
        printf("Test case %d: %lld\n",t+1,inv);
        
    }
}
