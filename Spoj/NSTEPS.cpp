#include <iostream>
#include <cmath>
using namespace std;
long long numberSteps(long long n,long long m )
{
    if(n%2==0)
    {
        if(m==n-2&&m>=0&&n>=0)
            return 2*n-2;
        else if(m==n&&n>=0)
            return 2*n;
        else return -1;
    }
    else
    {
        if(m==n-2&&m>=0&&n>=0)
            return 2*n-3;
        else if(m==n&&n>=0)
            return 2*n-1;
        else return -1;
    }
    return -1;
}
int main()
{
    long long t,z=0;
    cin>>t;
    while(z<t)
    {
        long long n,m;
        cin>>n;
        cin>>m;
        long long s=numberSteps(n,m);
        if(s>=0)
            cout<<s<<endl;
        else
            cout<<"No Number"<<endl;
        z++;
    }
}

