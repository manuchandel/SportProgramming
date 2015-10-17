#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a[4]={"192","442","692","942"};
    int t,z=0;
    cin>>t;
    while(z<t)
    {
        long long n;
        cin>>n;
        long long i=n/4;
        if(n%4==0)
            i--;
        long long j=n%4;
        if(j==0)
            j=4;
        if(i>0)
        cout<<i;
        cout<<a[j-1]<<endl;
        z++;
    }
}
