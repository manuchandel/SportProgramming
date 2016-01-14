#include <bits/stdc++.h>
using namespace std;
int find(int a[],int b){
    if(a[b]==-1)
        return b;
    int key=b,val=b;
    while(val!=-1){
        key=val;
        val=a[key];
    }
    int parent=key;
    key=b;val=b;
    while(val!=-1){
        key=val;
        val=a[key];
        if(val!=-1)
            a[key]=parent;
    }
    return parent;
    
}
int main()
{
    int N,k,i,a,b;
    scanf("%d",&N);
    int arr[N+1];
    int E[N+1];
    arr[0]=-1;
    E[0]=0;
    for(i=1;i<=N;i++){
        scanf("%d",&E[i]);
        arr[i]=-1;
    }
    int p1=0,p2=0;
    scanf("%d",&k);
    for(i=0;i<k;i++){
        scanf("%d%d",&a,&b);
        p1=find(arr,a);
        p2=find(arr,b);
        if(p1!=p2){
            arr[p1]=p2;
        }
    }
    int minimum[N+1];
    for(i=1;i<=N;i++)
        minimum[i]=INT_MAX;
    for(i=1;i<=N;i++){
        p1=find(arr,i);
        minimum[p1]=min(minimum[p1],E[i]);
    }
    int sum[N+1];
    memset(sum,0,sizeof(sum));
    for(i=1;i<=N;i++){
        p1=find(arr,i);
        if(E[i]==minimum[p1])
            sum[p1]+=1;
    }
    long long product=1;
    for(i=1;i<=N;i++){
       if(sum[i]){
            product= product* (long long)sum[i];
            product%=1000000007;
        }
    }
    printf("%lld\n",product);
   
}
