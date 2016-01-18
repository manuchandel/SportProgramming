#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int T,N,x,i;
   scanf("%d",&T);
   while(T--){
    vector<int> v;
    ll pr=1;
    bool flag=false;
    scanf("%d",&N);
    for(i=0;i<N;i++){
    	scanf("%d",&x);
    	if(x!=0)
    		v.push_back(x);
    	else flag=true;
    }
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++)
    	pr*=(ll)v[i];
    if(v.size()==0)
    	printf("0 0\n");
    else{
		if(v[0]>0){
			printf("%lld ",pr);
			if(!flag)
				printf("%d\n",v[0]);
			else printf("0\n");
			
    	}
    	else{
    		int max_neg=INT_MIN;
    		for(i=0;i<v.size();i++){
    			if(v[i]<0)
    				max_neg=max(max_neg,v[i]);
    		}
    		if(pr>0){
    			printf("%lld %lld\n",pr,(ll)pr/max_neg);
    		}
    		else{
    			if(v.size()==1){
    				if(flag)
    					printf("0 ");
    				else printf("%d ",v[0]);
    				printf("%lld\n",pr);
    					
    			}else	printf("%lld %lld\n",(ll)pr/max_neg,pr);
    		}
    	}
    	
    }
    	
   
    
    
    
    
    
   }
}
