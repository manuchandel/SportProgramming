#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long z=0;
    long long t;
    cin>>t;
    while(z<t)
    {
        long long m;
        long long n;
    cin>>m;
    cin>>n;
    char *array1=new char[n-m+1];
    for(long long i=0;i<=n-m;i++)
        array1[i]='0';
    for(long long i=2;i<=sqrt(n);i++)
    {
        long long k=ceil(m/i);
        if(k==0||k==1)
            k=i;
        //if(array1[i]=='0')
        for(long long j=i*k;j<=n;j+=i)
        if(j-m>=0)
              array1[j-m]='1';
    }
    for(long long i=m;i<n+1;i++)
        if(array1[i-m]=='0'&&i!=1)
            cout<<i<<endl;
    delete []array1;
    cout<<endl;
            z++;
    }

}
