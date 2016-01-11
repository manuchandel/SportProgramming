#include <bits/stdc++.h>
using namespace std;

int main()
{
    map< int, map<int, map <int, map< int,int > > > > mymap;
    int T,A,B,C,D,Q;
    string s,p,q;
   	cin>>s;
   	scanf("%d",&Q);
   	while(Q--){
   		scanf("%d%d%d%d",&A,&B,&C,&D);
   		if(mymap[A].find(B)!=mymap[A].end() && mymap[A][B].find(C)!=mymap[A][B].end() && 
   			mymap[A][B][C].find(D)!=mymap[A][B][C].end()){
   				if(mymap[A][B][C][D])
   					printf("Yes\n");
   				else printf("No\n");
   		}else{
   			p=s.substr(A-1,B-A+1);
   			q=s.substr(C-1,D-C+1);
   			if(p==q){
   				mymap[A][B][C][D]=1;
   				printf("Yes\n");
   			}else {
   				mymap[A][B][C][D]=0;
   				printf("No\n");
   			}
   		}
   	}
}
