#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
using namespace std;
int frequency(int *f,int mid,int n)
{
	int count=0;
	for(int i=mid+1;i<n;i++)
	{
		if(f[i]==f[mid])
		count++;
		else break;
	}
	for(int i=mid;i>=0;i--)
	{
		if(f[i]==f[mid])
		count++;
		else break;
	}
	return count;
}
int binarySearch(int n,int *f,int k)
{
	int st=0,end=n*n-1,mid=n*n/2;
	while(st<=end)
	{
		mid=(st+end)/2;
		if(k<f[mid])
			end=mid-1;
	
		else if(k>f[mid])
			st=mid+1;
		else
		return frequency(f,mid,n*n);
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	int *a=new int[n];
	int *b=new int[n];
	int *c=new int[n];
	int *d=new int[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
		scanf("%d",&c[i]);
		scanf("%d",&d[i]);
	}
	int *e=new int [n*n];
	int *f=new int [n*n];
	for(int i=0;i<n*n;i++)
	{e[i]=0;f[i]=0;}
	int m=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			e[m]=a[i]+b[j];
			f[m]=c[i]+d[j];
			m++;
		}
	}
	delete a,b,c,d;
	sort(f,f+n*n);
	long long counter=0;
	for(int i=0;i<n*n;i++)
	counter+=binarySearch(n,f,-1*e[i]);
	cout<<counter<<endl;
}
