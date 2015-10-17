#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
class c1
{
	public:
		c1() :value(0),weight(0){}
		int value;
		int weight;
};
int value1(c1 *c2,int n)
{
	int k=0;
	for(int i=0;i<n;i++)
	if(k<c2[i].value)
	k=c2[i].value;
	return k;
}
int maxval(c1 c[],int k,int m,c1 *c2,int b[])
{
	int max,new1;
	if(c[0].weight<=k)
	{
		c2[1].weight=c[0].weight;
		c2[1].value=c[0].value;
	}
	max=2;
	for(int i=1;i<m;i++)
	{
		new1=max;
		for(int j=0;j<max;j++)
		{
			if(c2[j].weight+c[i].weight<=k)
			{
				int temp=c2[new1].weight+c2[j].weight+c[i].weight;
				int temp2=c2[new1].value+c2[j].value+c[i].value;
				if(b[temp2]>temp)
				{
					c2[new1].weight=temp;
					c2[new1].value=temp2;
					b[temp2]=temp;
					new1++;
				}
			}
		}
		max=new1;
	}
	return max;
}
int main()
{
	//srand(time(0));
	int t;
	c1 c[50];
	for(int i=0;i<50;i++)
	c1 c[i];
	c1 *c2=new c1[2000];
	for(int i=0;i<2000;i++)
	c1 c2[i];
	cin>>t;
	int valarr[1251];
	while(t--)
	{
	for(int i=0;i<1251;i++)
	valarr[i]=1000001;
		int k,m;
		scanf("%d",&k);
		scanf("%d",&m);
		//cout<<"finish m"<<endl;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&c[i].weight);
			scanf("%d",&c[i].value);
		}
		
		int index=maxval(c,k,m,c2,valarr);
		int value=value1(c2,index);
		cout<<"Hey stupid robber, you can get "<<value<<"."<<endl;
		cout<<endl;
		for(int i=0;i<index;i++)
		{
			c2[i].value=0;
			c2[i].weight=0;
		}
		//double z=((double)clock()-v)/CLOCKS_PER_SEC;
		//cout<<"time = "<<z<<endl;
	}
	//int h;
	//cin>>h;
}
