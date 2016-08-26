#include <bits/stdc++.h>
#define MAX 1025
#define ll long long
using namespace std;
ll bit[1025][1025];
void update(int x, int y, ll val){
    int xindex=x+1;
    int yindex=y+1;
    while(xindex<MAX){
        yindex=y+1;
        while(yindex<MAX){
            bit[xindex][yindex]+=val;
            yindex=yindex+(yindex&(-yindex));
        }
        xindex=xindex+(xindex&(-xindex));
    }
}

ll query(int x1, int y1){
    ll sum=0;
    int yindex=y1+1;
    int xindex=x1+1;
    while(xindex>0){
        yindex=y1+1;
        while(yindex>0){
            sum+=bit[xindex][yindex];
            yindex=yindex-(yindex&(-yindex));
        }
        xindex=xindex-(xindex&(-xindex));
    }
    return sum;
}
ll query(int x1, int y1, int x2, int y2){

    ll a=query(x2,y2);
    ll b= query(x1-1,y1-1);
    ll c=query(x1-1,y2);
    ll d=query(x2,y1-1);
    return (a-c+b-d);
}
int main(){
    int t,N,x1,x2,y1,y2;
    ll val;
    scanf("%d",&t);
    char com[5];
    while(t--){
        memset(bit,0,sizeof(bit));
        scanf("%d",&N);
        while(1){
            scanf(" %s",com);
            //printf("%s\n",com );
            if(strcmp(com,"SET")==0){
                scanf("%d%d%lld",&x1,&y1,&val);
                ll v=query(x1,y1,x1,y1);

                update(x1,y1,val-v);
            }else if(strcmp(com,"SUM")==0){
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                printf("%lld\n",query(x1,y1,x2,y2));
            }
            else break;
        }
        printf("\n");
    }
}
