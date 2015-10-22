#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int *a1=new int[s.length()];
        int j=0;
        for(int i=0;i<s.length();i++)
            a1[i]=0;
            if(s.length()!=0)
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
                a1[j]+=1;
            if(s[i]!=s[i+1])
                j++;
        }
        int ways=0;
        for(int i=0;i<s.length();i++)
            ways+=a1[i];
          cout<<pow(2,ways)<<endl;
            delete []a1;
    }
}



