#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T,i,n;
    scanf("%d",&T);
    set<string> myset;
    string s;
    while(T--){
    	scanf("%d",&n);
    	for(i=0;i<n;i++){
    		cin>>s;
    		myset.insert(s);
    	}
    	for(auto it=myset.begin();it!=myset.end();it++)
    		printf("%s\n",(*it).c_str());
    	myset.clear();
    }
}
