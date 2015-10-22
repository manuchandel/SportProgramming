#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int t,m;
	long long a,b,c;
	long long n;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		cin>>a>>b>>c;
		n=a*b*c-1;
		m=ceil(log2(a))+ceil(log2(b))+ceil(log2(c));
		cout<<"Case #"<<i<<": "<<n<<" "<<m<<endl;
	}
}
