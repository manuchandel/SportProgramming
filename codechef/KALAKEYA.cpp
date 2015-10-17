#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	vector<int> temp;
	vector<int> v(100001,0);
	cin>>t;
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(k>n/2)
		{
			printf("-1\n");
		}
		else if(k==0)
		{
			for(int i=1;i<=n;i++)
			printf("%d ",i);
			printf("\n");	
		}
		else
		{
		for(int i=1;i<=k;i++)
		{
			for(int j=i;j<=n;j+=k)
				temp.push_back(j);
			for(int j=0;j<temp.size()-1;j+=2)
				swap(temp[j],temp[j+1]);
				
			if(temp.size()%2==1 && temp.size()>=1)
				swap(temp[temp.size()-1],temp[temp.size()-2]);
			int l=i;
			for(int j=0;j<temp.size();j+=1)
			{
				v[l]=temp[j];
				l+=k;
			}
			temp.clear();
		}
		
		for(int i=n-k+1;i<=n;i++)
		{
			temp.push_back(v[i]);
		}
		sort(temp.begin(),temp.end());
		
		for(int i=n-k+1;i<=n;i++)
		{
			v[i]=temp[i-n+k-1];
		}
		
		for(int i=1;i<=n;i++)
			printf("%d ",v[i]);
		printf("\n");
		
		temp.clear();
	}
	}
}
