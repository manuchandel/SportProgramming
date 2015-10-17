#include <iostream>
using namespace std;
int main()
{
	int t,n;
	bool flag;
	scanf("%d",&t);
	int a[1001];
	int b[1001];
	for(int j=0;j<t;j++)
	{
		flag=true;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			if(a[i]>n-1)
			{
				flag=false;
				cout<<"NO"<<endl;
				break;
			}
			if(b[a[i]+1]==0)
			{
				b[a[i]+1]=a[i];
				
			}
			else
			b[n-a[i]]=a[i];
					
		}
		if(flag)
		for(int i=1;i<=n;i++)
		{
			if(b[i]==0)
			{
				flag=false;
				cout<<"NO"<<endl;
				break;
			}
		
		}
		for(int i=1;i<=n;i++)
		b[i]=0;
		
		if(flag)
		cout<<"YES"<<endl;
		
		
	}
}
