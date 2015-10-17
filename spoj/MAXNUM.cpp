#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
using namespace std;

void pop(int &p)
{
	if(p>0)
	p--;
}
void push( char m,char *a,int &p,int len)
{
	if(p<len)
	{
		a[p]=m;
		p++;
	}
	
}
int mainmethod(int k,string &x,char *a,int len)
{
	int p=1;int i=1;
	while(i<x.length())
	{
		if(p>0)
		{
			if((int)x[i]<=(int)a[p-1])
			{
				push(x[i],a,p,len-k);
				i++;
			}
			else if(len-i>len-k-p)
			 pop(p);
			else
			{
				push(x[i],a,p,len-k);
				i++;
			}
		}
		
		if(p==0)
		{
			push(x[i],a,p,len-k);
			i++;
		}
	}	

}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	string x;
	int k;
	cin>>x;
	scanf("%d",&k);
	char *a=new char[x.length()-k];
	a[0]=x[0];
	if(x.length()!=k)
	{
	mainmethod(k,x,a,x.length());
	for(int i=0;i<x.length()-k;i++)
	{
		cout<<a[i];
	}}
	cout<<endl;
	}
}
