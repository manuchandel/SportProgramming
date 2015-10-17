#include <stdio.h>
using namespace std;
int main()
{

	
	long long  t,m,p,count;
	int n,temp;
	bool flag;
	int a[100001];
		long long sum[100001];
	scanf("%lld",&t);
	//int *c=new int[100001];
	while(t--)
	{
		scanf("%d",&n);
		m=0;
		for(int i=n;i>=1;i--)
		{
		scanf("%d",&a[i]);
		m+=a[i];
		}
		if(m%2==0)
		{
			for(int k=1;k<=n;k++)
			{
				sum[k]=sum[k-1]+a[k];
				p=k*(k-1);
				count =0;
				for(int j=k+1;j<=n;j++)
				{
			 		temp=a[j];
				if(k<a[j])
					temp=k;
					count+=temp;
				}
				if(sum[k]>p+count)
				{
					flag=false;
					break;
				}
				else flag=true;
			}
		}
		else
		flag=false;
		if(flag)
			printf("HAPPY\n");
		else
			printf("SAD\n");
	}
}


