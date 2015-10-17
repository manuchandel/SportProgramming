#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
void nextpalindrome(short array[],int size);
int main()
{
	int d;
	int h=0;
	cin>>d;
	while(h<d){
	string x;
	cin>>x;
	string t;
	short array[x.length()];
	for(int i=0;i<x.length();i++)
	{
		t=x.at(i);
		array[i]=atoi(t.c_str());
	}
	++array[x.length()-1];
	for(int i=x.length()-1;i>0;i--)
	{
		if(array[i]/10>0)
		{
			array[i]%=10;
			array[i-1]++;
		}
	}
	array[0]%=10;
	nextpalindrome( array,x.length());
	h++;
}
	
	
}

void nextpalindrome(short array[],int size)
{

	bool flag=true;
	for(int i=0;i<size-1;i++)
	{
		if(array[i]!=0)
		{
			flag=false;
			break;
		}
	}

	if(flag!=true)
	{
		
		
			if(size%2==0)
			{
			
				int i=1;
				while(i<size/2+1)
				{
					if(array[size/2-i]>array[size/2+i-1])
					break;
					else if(array[size/2-i]<array[size/2+i-1])
					{
						array[size/2-1]++;
						break;
					}
					i++;
				
					
				}
						for(int k=size/2-1;k>0;k--)
						{
								if(array[k]/10>0)
								{
									array[k]%=10;
									array[k-1]++;
								}							
						}
			}
		
			if(size%2==1)
			{
				int i=1;
				while(i<size/2+1)
				{
					if(array[size/2-i]>array[size/2+i])
					break;
					else if(array[size/2-i]<array[size/2+i])
					{
						array[size/2]++;
						break;
					}
					i++;
				
					
				}
			
					for(int k=size/2;k>0;k--)
					{
						if(array[k]/10>0)
						{
							array[k]%=10;
							array[k-1]++;
						}
						
					}
			}
		
	
		for(int i=0;i<size/2;i++)
			array[size-1-i]=array[i];
		for(int i=0;i<size;i++)
			cout<<array[i];
			cout<<endl;
	}
	else
	{
	cout<<"1";
	for(int i=0;i<size-1;i++)
	cout<<"0";
	cout<<"1";
	cout<<endl;
	}
	
}
