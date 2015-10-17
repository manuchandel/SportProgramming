#include<iostream>
#include <cmath>
using namespace std;
int main()
{
    int p=1;
    while(p==1){
    int n;
    cin>>n;
    if(n==-1)
        break;
    int *a=new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int avg=0;
    for(int i=0;i<n;i++)
        avg+=a[i];
        int c=avg;
    avg/=n;
    if(n*avg!=c)
        cout<<"-1"<<endl;
    else
    {
        int sum=0;
        for(int i=0;i<n;i++)
           {
               if(avg-a[i]>0)
                sum+=avg-a[i];
               else sum+=a[i]-avg;
           }
        cout<<sum/2<<endl;
    }
    delete []a;
    }

}
