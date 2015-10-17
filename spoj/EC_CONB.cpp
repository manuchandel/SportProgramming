#include <iostream>
#include <cmath>
using namespace std;
int noOfBits(long long c)
{
	int i=0;
	while(1)
	{
		long long q=pow(2,i);
		if(q>c)
		return i;
		else if(q==c)
		return i+1;
		i++;
	}
}
void method(int c)
{
	int n=noOfBits(c);
	int s=pow(2,n-1);
	int *a=new int [n];
	for(int i=0;i<n;i++)
	{
		a[i]=s&c;
		a[i]=a[i]>>(n-i-1);
		c=c<<1;
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans=ans|a[i];
	}
	cout<<ans<<endl;
}
int main()
{
	int b;
	cin>>b;
	int *f=new int[b];
	for(int i=0;i<b;i++)
	cin>>f[i];
	for(int i=0;i<b;i++)
	{
	if(f[i]%2==0)
	method(f[i]);
	else
	{
		cout<<f[i]<<endl;
	}
}
}

