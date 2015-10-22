#include <iostream>
using namespace std;
void print(short *a,int n)
{
	for(int i=1;i<=n;i++)
	cout<<a[i];
}
void nextsmall(short *a,int n,int j)
{
	int orig [10];
	for(int i=0;i<10;i++)
	orig[i]=0;
	for(int i=j;i<=n;i++)
		orig[a[i]]+=1;
	
	bool flag=false;
	for(int i=a[j-1]+1;i<10;i++)
	{
		if(orig[i]>0)
		{
			orig[i]--;
			orig[a[j-1]]++;
			print(a,j-2);
			cout<<i;
			flag=true;
			break;
		}
		
	}
	if(!flag)
	{
		print(a,j-2);
		cout<<a[j];
		orig[a[j-1]]++;
		orig[a[j]]--;
	}
	
	for(int i=0;i<10;i++)
		for(int k=0;k<orig[i];k++)
			cout<<i;
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		short *a=new short[n+1];
		for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		int j=0;
		for(int i=n;i>1;i--)
		{
			if(a[i]>a[i-1])
			{
				//swap(a[i],a[i-1]);
				j=i;
				break;
			}
		}
	
		if(j==0)
		cout<<-1;
		else
		nextsmall(a,n,j);
		cout<<endl;
	}
}







