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
    int N,Q,a,b,p1,p2,i;
    scanf("%d%d",&N,&Q);
    int arr[N+1];
    for(i=1;i<=N;i++){
        arr[i]=-1;
        mymap[i]=i;
    }
    while(Q--){
        scanf("%d%d",&i,&a);
        p1=find(arr,a);
        
        if(i==1){
        	scanf("%d",&b);
        	p2=find(arr,b);
        	if(p1!=p2){
        		arr[p1]=p2;
        		mymap.erase(p1);
        	}
        }else if(i==2){
        	mymap[p1]=a;
        }else printf("%d\n",mymap[p1]);
  
    }
}
