#include <bits/stdc++.h>
#define MAX 100001
#define ll long long
using namespace std;

int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    while(N>0 || M>0){
        double b=(double)(M-N+1)/(M+1);
        printf("%0.6lf\n",max(0.0,b));
        scanf("%d%d",&N,&M);
    }
}
