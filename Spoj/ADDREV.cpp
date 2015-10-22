#include<iostream>
#include <string>
#include<stdlib.h>
using namespace std;

int main()
{
	int d;
	cin>>d;
	while(d--)
	{
		string a, b;
		cin>>a;
		cin>>b;
		for(int i=0;i<a.length()/2;i++)
        {
            char c=a[i];
             a[i]=a[a.length()-1-i];
             a[a.length()-1-i]=c;
        }

        for(int i=0;i<b.length()/2;i++)
        {
            char c=b[i];
             b[i]=b[b.length()-1-i];
             b[b.length()-1-i]=c;
        }
        long long a1=atoi(a.c_str());
        long long a2=atoi(b.c_str());
        a1+=a2;
        while(a1%10==0)
            a1/=10;
        while(a1>0)
        {
            cout<<a1%10;
            a1/=10;
        }
        cout<<endl;

	}
}
