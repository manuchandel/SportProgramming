#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int t,n;
	
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%d",&n);
		int *a=new int [n];
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		int *list=new int[100001];
		int *sum=new int[100001];
		for(int i=0;i<n;i++)
		{
			sum[i]=0;
			list[i]=0;
		}
		list[0]=0;
		list[1]=a[0];
		sum[0]=1;
		sum[list[1]]=1;
		int new1=2;
		int max=2;
		int count=list[1];
		for(int i=1;i<n;i++)
		{
			new1=max;
			for(int j=0;j<max;j++)
			{
				if(sum[a[i]+list[j]]==0)
				{
					list[new1]=a[i]+list[j];
					sum[a[i]+list[j]]=1;
					count+=list[new1];
					new1++;
				}
			}
			max=new1;
		}
	printf("%d\n",count);
	delete a,list,sum;	
	}
}
