#include <iostream>
#include <cmath>
using namespace std;

int powerFinder(int i,int n)
{
    long long  c=i;
	int sum=0;
	int m=1;
	while(m!=0)
	{
		m=n/c;
		sum+=m;
        c*=i;
	}
	return sum;
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n+1];
	for(int i=0;i<=n;i++)
        a[i]=0;
	for(int i=2;i<=sqrt(n);i++)
        for(int j=i*i;j<=n;j+=i)
            a[j]=1;
	int *array1=new int[n];
	int l=0;
	for(int i=2;i<=n;i++)
	{
	    if(a[i]==0){
            array1[l]=i;
            l++;
	    }
	}
	int *a2=new int [l];
	for(int i=0;i<l;i++)
	{
		int m=powerFinder(array1[i],n);
		a2[i]=m;
	}
	for(int i=0;i<l;i++)
	{
		if (i==l-1)
		{
			cout<<array1[i]<<"^"<<a2[i]<<endl;
			break;
		}
		cout<<array1[i]<<"^"<<a2[i]<<" * ";
	}
	delete [] a;
	delete []array1;
	delete []a2;
}
