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
int minDif(map<int,int> &mymap){
	map<int,int> :: iterator it1=mymap.begin();
	map<int,int> :: iterator it2=mymap.begin();
	int ans=INT_MAX;
	it2++;
	if(it2==mymap.end())
		return 0;
	for(;it2!=mymap.end();it2++){
		if(it1->second>1)
			return 0;
		ans=min(ans,it2->first-it1->first);
		it1++;
	}
	if(it1->second>1)
		return 0;
	return ans;
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
    
    	printf("%d\n",minDif(mymap1));
    }
}
