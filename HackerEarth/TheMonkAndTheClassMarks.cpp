#include <bits/stdc++.h>
using namespace std;

int main()
{
   int i,j,n;
   string s;
   map <string,int> mymap[101];
   scanf("%d",&n);
   while(n--){
   	cin>>s>>i;
   	if(mymap[i].find(s)!=mymap[i].end())
   		mymap[i][s]+=1;
   	else mymap[i][s]=1;
   }
   for(i=100;i>0;i--){
   	if(!mymap[i].empty()){
   		for(auto it=mymap[i].begin();it!=mymap[i].end();it++){
   			for(j=0;j<mymap[i][(it->first)];j++)
   				printf("%s %d\n",(it->first).c_str(),i);
   		}
   	}
   }
}

