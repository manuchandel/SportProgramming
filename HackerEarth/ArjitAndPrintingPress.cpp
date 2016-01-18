#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T,n,m,i,j;
    char x[10001];
    char y[10001];
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",x,y);
        n=strlen(x);
        m=strlen(y);
        sort(y,y+m);
        i=0;j=0;
        while(i<n){
            if(j<m && x[i]>y[j]){
                printf("%c",y[j]);
                j++;
            }else printf("%c",x[i]);
            i++;
        }
        printf("\n");
    }
}
