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
    map<int,int> mymap;
    map<int,int> mymap1;
    int N,Q,a,b,p1,p2,i;
    scanf("%d%d",&N,&Q);
    int arr[N+1];
    for(i=1;i<=N;i++){
    	arr[i]=-1;
    	mymap[i]=1;
    }
    mymap1[1]=N;
    while(Q--){
    	scanf("%d%d",&a,&b);
    	p1=find(arr,a);
    	p2=find(arr,b);
    	if(p1!=p2){
    		arr[p1]=p2;
    		mymap1[mymap[p1]]-=1;
    		if(mymap1[mymap[p1]]==0)
    			mymap1.erase(mymap[p1]);
    		mymap1[mymap[p2]]-=1;
    		if(mymap1[mymap[p2]]==0)
    			mymap1.erase(mymap[p2]);
    		if(mymap1.find(mymap[p2]+mymap[p1])==mymap1.end())
    			mymap1[mymap[p2]+mymap[p1]]=1;
    		else mymap1[mymap[p2]+mymap[p1]]+=1;
    		mymap[p2]+=mymap[p1];
    		mymap.erase(p1);
    	}
    	map<int,int> :: iterator it=mymap1.end();
    	it--;
    	printf("%d\n",(it->first)-(mymap1.begin()->first));
    }
}
