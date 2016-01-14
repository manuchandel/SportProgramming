#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,K,a,b,i;
    map<int,int> mymap;
    scanf("%d%d",&N,&K);
    while(N--){
    	scanf("%d%d",&a,&b);
    	mymap.erase(b);
    }
    printf("%d\n",mymap.size());
}
