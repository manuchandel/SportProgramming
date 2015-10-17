#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
 void add(char *array1,char *array2,int n,char *array3)
	{
		int carry=0;
		for(int i=0;i<n;i++)
		{
			int x=array1[n-1-i]-'0';
			int y=array2[n-1-i]-'0';
			int sum=x+y+carry;
			if(sum>9)
			{	carry=sum/10;
				sum=sum%10;
			}
			else carry=0;
			array3[n-1-i]=char(sum+'0');	
		}
	}
void multiply(char *array1,char *array2,char *array3,int n,int m)
	{
		int base=1;
		for(int i=2;i<=m&&i<100;i++)
		{
			int carry=0;
			int t=i%10;
			for(int j=0;j<n;j++)
			{
				int x=t*(array3[n-1-j]-'0')+carry;
				if(x>9)
				{
					carry=x/10;
					x%=10;
				}
				else carry=0;
				array1[n-1-j]=char(x+'0');
			}
			t=i/10;
			carry=0;
			for(int j=0;j<n-1;j++)
			{
				int x=t*(array3[n-1-j]-'0')+carry;
				if(x>9)
				{
					carry=x/10;
					x%=10;}
				else carry=0;
				array2[n-2-j]=char(x+'0');
			}
			add(array1,array2,n,array3);
		}
	}
int main()
    {
    	int n=160;
    	int t;
    	cin>>t;
    	while(t--)
    	{
    	 int m;
    	 cin>>m;
       	 char *array1=new char[n];
       	 char *array2=new char[n];
       	 char *array3=new char[n];
       	 for(int i=0;i<n;i++)
       	 {	
       	 	array1[i]='0';
       		array2[i]='0';
       		array3[i]='0';
       	 }
       	 array3[n-1]='1';
       	 multiply(array1,array2,array3,n,m);
       	 int i;
       	 for(i=0;i<n;i++)
       		if(array3[i]!='0')
       			break;
       	for(int j=i;j<n;j++)
       		cout<<array3[j];
       	if(m==100)
       		cout<<"00";
       		cout<<endl;
      }
    }


