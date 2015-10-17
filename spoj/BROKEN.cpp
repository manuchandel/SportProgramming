#include <stdio.h>
#include <string>
using namespace std;
int nodv(int a[])
{
	int sum=0;
	for(int i=0;i<=255;i++)
	{
		if(a[i]!=0)
		sum++;
	}
	return sum;
}
int mainmethod(char s[],int m,int len,int a[])
{
	if(m>len)
	return len;
	int max=m;
	
	for(int i=0;i<256;i++)
		a[i]=0;
	int rear=0,front=m-1;
	for(int i=0;i<m;i++)
		a[(int)s[i]]+=1;
	while(front<=len-1)
	{
		//cout<<"i am front "<<front<<endl;
		//cout<<"i am rear "<<rear<<endl;
		if(front-rear+1>max)
			max=front-rear+1;
		if(front!=len-1)
		{if(a[(int)s[front+1]]!=0||nodv(a)<m)
		{
			front++;
			a[(int)s[front]]+=1;
			//cout<<"i am max "<<max<<endl;
			
		}
		
		else
		{
			front++;
			a[(int)s[front]]+=1;
			while(1)
			{
				a[(int)s[rear]]-=1;
				rear++;
				if(nodv(a)<=m)
				break;
			}
		}}
		if(front-rear+1>max)
			max=front-rear+1;
		if(front==len-1)
		break;
	}
	return max;
	
}
int main()
{
	char input[1000002];
	char c;
	int m;
	int a[256];
	while(1)
	{
		scanf("%d",&m);
		int len=0;
		if(m==0)
		break;
		getchar();
		while((c=getchar())!='\n')
		{
			input[len]=c;
			len++;
		}
		//input[len]='\0';
		//printf("%c\n",input[len]);
		printf("%d\n",mainmethod(input,m,len,a));
	}
	
}


