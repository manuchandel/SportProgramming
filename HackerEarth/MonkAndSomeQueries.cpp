#include <bits/stdc++.h>
using namespace std;

int main()
{
   	map<int,int> mymap;
    int Q,i,X;

	scanf("%d",&Q);
    while(Q--){
    	scanf("%d",&i);
    	if(i==1){
    		scanf("%d",&X);
    		if(mymap.find(X)==mymap.end())
    			mymap[X]=1;
    		else mymap[X]+=1;
    	}else if(i==2){
    		scanf("%d",&X);
    		if(mymap.find(X)!=mymap.end()){
    			if(mymap[X]==1)
    				mymap.erase(X);
    			else mymap[X]-=1;
    		}else printf("-1\n");
    	}else if(i==3){
    		if(mymap.empty())
    			printf("-1\n");
    		else{
    			map <int,int> ::iterator it=mymap.end();
    			it--;
    			printf("%d\n",it->first);
    		}
    	}else if(i==4){
    		if(mymap.empty())
    			printf("-1\n");
    		else{
    			map<int,int> ::iterator it=mymap.begin();
    			printf("%d\n",it->first);
    		}
    	}
    }
}
