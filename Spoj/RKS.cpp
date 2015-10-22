#include <iostream>
#include <ctime>
using namespace std;
class c1
{
	public:
		c1():data(0),freq(0){}
		int data;
		int freq;
};
int max1(c1 *c,int n)
{
	int j=0;
	int k=c[0].freq;
	for(int i=0;i<n;i++)
	if(k<c[i].freq)
	{
		k=c[i].freq;
		j=i;
	}
	return j;
}
int check(c1 *c,int n,int m)
{
	for(int i=0;i<n;i++)
	{
		if(c[i].data==m)
		return i;
	}
	return n;
}
int main()
{
	//clock_t v;
	//v=clock();
	int n,m,j,f;
	scanf("%d",&n);
	c1 *c=new c1[n];
	int *b=new int[n];
	scanf("%d",&m);
		m++;
		for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
		for(int i=0;i<n;i++)
       	c1 c[i];
		c[0].data=b[0];
		c[0].freq=1;
		j=1;
		for(int i=1;i<n;i++)
		{
			int temp=check(c,j,b[i]);
				c[temp].data=b[i];
				c[temp].freq+=1;
				if(temp==j)
				j++;
		}
		for(int i=0;i<j;i++)
		{
			f=max1(c,j);
			for(int l=0;l<c[f].freq;l++)
			cout<<c[f].data<<" ";
			c[f].freq=0;
		}
		cout<<endl;
		delete b,c;
	//double z=((double)(clock()-v)/CLOCKS_PER_SEC);
	//cout<<"\n I AM TIME "<<z;
	//int h;
	//cin>>h;
}

