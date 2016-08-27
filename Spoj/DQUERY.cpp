#include <bits/stdc++.h>
#define ll long long
#define MAX 300001
#define mod 1000000007
using namespace std;
int bit[MAX];
int *pos=new int[1000001];
void update(int i, int val){
    int index=i+1;
    while(index<MAX){
        bit[index]+=val;
        index=index+(index&(-index));
    }
}
int query(int i){
    int sum=0;
    int index=i+1;
    while(index>0){
        sum+=bit[index];
        index=index-(index&(-index));
    }
    return sum;
}
int queryR(int l,int r){
    return query(r)-query(l-1);
}
struct Query{
    int l,r,i;
};
bool comp(Query q1,Query q2){
    return q1.r<q2.r;
}
int main(){
    int i,N,Q;
    int A[30000];
    memset(bit,0,sizeof(int)*MAX);
    memset(pos,-1,sizeof(int)*1000001);
    Query q[200000];
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&A[i]);
    scanf("%d",&Q);
    for(i=0;i<Q;i++){
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].l-=1;
        q[i].r-=1;
        q[i].i=i;
    }
    sort(q,q+Q,comp);
    int ans[Q];
    int j=0;
    for(i=0;i<N;i++){
        if(pos[A[i]]!=-1)
            update(pos[A[i]],-1);  
        pos[A[i]]=i;
        update(i,1);
        while(j<Q && q[j].r==i){
            ans[q[j].i]=queryR(q[j].l,q[j].r);
            j++;
        }
    }
    for(i=0;i<Q;i++)
        printf("%d \n",ans[i]);
    printf("\n");
}
