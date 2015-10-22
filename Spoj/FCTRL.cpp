#include<iostream>
#include<cmath>
using namespace std;
int noOfZeros(int m);
int main()
{
	int n;
	cin>>n;
	int i=0;
	while(i<n)
	{
		int m;
		cin>>m;
		cout<<noOfZeros( m)<<endl;
		i++;
	}
}
int noOfZeros(int m)
{
	int i=1;
	int sum=0;
	int p=1;
	while(p>0)
	{
		 p=m/pow(5,i);
		sum+=p;
		i++;
	}
	return sum;
}
