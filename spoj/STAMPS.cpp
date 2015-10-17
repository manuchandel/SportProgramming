#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int t,n,no,count;
	int a[1000];
	scanf("%d",&t);
	for(int m=1;m<=t;m++)
	{
		count=0;
		scanf("%d",&no);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
		int j=0;
		bool flag=false;
		for(int i=n-1;i>=0;i--)
		{
			count+=a[i];
			if(count>=no)
			{
				flag=true;
				j=n-i;
				break;
			}
		}
		if(flag)
		{
			cout<<"Scenario #"<<m<<":"<<endl;
			cout<<j<<endl;
			cout<<endl;
		}
		else
		{
			cout<<"Scenario #"<<m<<":"<<endl;
			cout<<"impossible"<<endl;
			cout<<endl;
		}
	}
}
