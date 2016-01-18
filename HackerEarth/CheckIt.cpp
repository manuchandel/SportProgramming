#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,M,T,i,x;
    bool flag;
    int a[40000];
    int b[40000];
    bool c[5000];
    scanf("%d",&T);
    while(T--){

        scanf("%d%d",&N,&M);
        flag=true;
        for(i=0;i<N;i++)
        	c[i]=false;
        for(i=0;i<M;i++)
            scanf("%d%d",&a[i],&b[i]);
        for(i=1;i<N;i++){
            scanf("%d",&x);
            if(c[a[x-1]-1] && c[b[x-1]-1])
            	flag=false;
            c[a[x-1]-1]=c[b[x-1]-1]=true;
            
        }
        if(flag)
            printf("YES\n");
        else printf("NO\n");
        
    }
}
