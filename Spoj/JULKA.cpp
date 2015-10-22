#include <iostream>
#include <string>
using namespace std;
string removeLeadingZeros(char a[],int n)
{
	int count=0;
	for(int i=0;i<n;i++)
		if(a[i]!='0')
		{
			count=i;
			break;
		}
	char b[n-count];
	for(int i=0;i<n-count;i++)
	b[i]=a[i+count];
	string newString(b,n-count);
	return newString;
}
string divideBy2(string s)
{
	int q,r=0,x,n=s.length();
	char a[n];
	for(int j=0;j<n;j++)
	{
		x=r*10+(s[j]-'0');
		q=x/2;
		r=x%2;
		a[j]=char(q+'0');
	}
	return removeLeadingZeros(a,n);	
}
void ninesComplement(char a[],int n)
{
	int x;
	for(int i=1;i<n;i++)
	{
		x=a[i]-'0';
		a[i]=char((9-x)+'0');
	}
}
string add(char a[],char b[],int n)
{
	int x,y,sum,carry=0;
	char c[n];
	for(int i=n-1;i>=0;i--)
	{
		x=a[i]-'0';
		y=b[i]-'0';
		sum=x+y+carry;
		if(sum>9)
		{
			carry=sum/10;
			sum=sum%10;
		}
		else
		carry=0;
		c[i]=char(sum+'0');
	}
	return removeLeadingZeros(c,n);
}
string subtract(char a[],char b[],int n)
{
	ninesComplement(b,n);
	
	string x=add(a,b,n);
	char c[x.length()-1];
	for(int i=0;i<x.length();i++)
	c[i]=x[i+1];
	char d[x.length()-1];
	for(int i=0;i<x.length();i++)
	d[i]='0';
	d[x.length()-2]=x[0];
	return divideBy2(add(c,d,x.length()-1));
}
int main()
{
	for(int h=0;h<10;h++){
	string s1,s2,natalia,klaudia;
	cin>>s1>>s2;
	bool flag=false;
	if(s1.length()==s2.length())
	for(int i=0;i<s1.length();i++)
	{
		if(s1[i]!=s2[i])
		{
			flag=true;
			break;
		}
	}
	else
	flag=true;
	if(flag)
	{
	int n=s1.length()+1;
	int m=s2.length();
	char a[n], b[n];
	for(int i=1;i<n;i++)
	{
		a[i]=s1[i-1];
		b[i]='0';
	}
	b[0]='0';
	a[0]='0';
	for(int i=0;i<m;i++)
		b[n-1-i]=s2[m-1-i];
	natalia=subtract(a,b,n);
	char c[n],d[n];
	for(int i=0;i<n;i++)
	{
		c[i]='0';
		d[i]='0';
	}	
	for(int i=0;i<m;i++)
		d[n-1-i]=s2[m-1-i];
	for(int i=0;i<natalia.length();i++)
		c[n-1-i]=natalia[natalia.length()-1-i];
	klaudia=add(c,d,n);
	cout<<klaudia<<endl<<natalia<<endl;
	}
	else
	cout<<s1<<endl<<"0"<<endl;
}
}
