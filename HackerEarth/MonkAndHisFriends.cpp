#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n,m,T,i;
   long long candies;
   unordered_map<long long,int> mymap;
   scanf("%d",&T);
   while(T--){
   	scanf("%d%d",&n,&m);
   	for(i=0;i<n;i++){
   		scanf("%lld",&candies);
   		mymap[candies]=1;
   	}
   	while(m--){
	   	scanf("%lld",&candies);
	   	if(mymap.find(candies)!=mymap.end())
	   		printf("YES\n");
	   	else printf("NO\n");
	   	mymap[candies]=1;
   	}
   	mymap.clear();
   }
   
}

