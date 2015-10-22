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
int maxval(c1 c[],int k,int m,c1 *c2,int *b)
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
			if(c2[j].weight+c[i].weight<=k&&c2[j].weight+c[i].weight>=0)
			{
				int temp=c2[new1].weight+c2[j].weight+c[i].weight;
				int temp2=c2[new1].value+c2[j].value+c[i].value;
				if(b[temp]<temp2)
				{
					c2[new1].weight=temp;
					c2[new1].value=temp2;
					b[temp]=temp2;
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
	c1 c[500];
	for(int i=0;i<500;i++)
	c1 c[i];
	c1 *c2=new c1[10000001];
	for(int i=0;i<5001;i++)
	c1 c2[i];
	int *wtarr=new int[20000001];
		int k,m;
		scanf("%d",&k);
		scanf("%d",&m);
		for(int i=0;i<=10000001;i++)
		wtarr[i]=0;
		for(int i=0;i<m;i++)
		{
			
			scanf("%d",&c[i].value);
			scanf("%d",&c[i].weight);
		}
		
		int index=maxval(c,k,m,c2,wtarr);
		int value=value1(c2,index);
		cout<<value<<endl;
}
