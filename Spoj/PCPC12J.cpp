#include<iostream>
using namespace std;
int main()
{
	int l;
	cin>>l;
	cout<<endl;
	int z=0;
	while(z<l)
	{
		int n;
		cin>>n;
		int list[n];
		for(int i=0;i<n;i++)
		cin>>list[i];
		int array[101];
		for(int i=0;i<101;i++)
		array[i]=0;
		for(int i=0;i<n;i++)
		array[list[i]]+=1;
		
		int k=-1;
		int j=2;
		bool flag=false;
		for(int i=1;i<101;i++)
		{
			if(k<array[i]&&array[i]%i==0)
				{
					k=array[i];
					j=i;
				}
		}
		for(int i=1;i<101;i++)
		{
			if(array[i]%i==0&&array[i]!=0)
			{
				flag=true;
				break;
			}
		}
		
		
		if(k%j==0&&k!=0)
		 cout<<j<<endl;
		 if(flag==false)
		 cout<<"-1"<<endl;
		 
		 z++;
		
}
}
