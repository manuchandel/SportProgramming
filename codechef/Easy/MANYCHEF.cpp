#include <iostream>
using namespace std;
#define slang "FEHC"
using namespace std;
void swap(char &a,char &b){
  char c=a;
  a=b;
  b=c;
}
void manyChefs(string &s){
  int i,j;
  int n=s.length();
  for(i=0;i<n/2;i++)
    swap(s[i],s[n-i-1]);
  for(i=0;i<n-3;i++){
    if((s[i]=='?' || s[i]=='F') && (s[i+1]=='?' || s[i+1]=='E') && (s[i+2]=='?' || s[i+2]=='H') && (s[i+3]=='?' || s[i+3]=='C'))
        s.replace(i,4,slang);
    else if(s[i]=='?') s[i]='A';
  }
  for(;i<n;i++)
    if(s[i]=='?')
      s[i]='A';
  for(i=0;i<n/2;i++)
    swap(s[i],s[n-i-1]);
}
int main()
{
  int T;
  string s;
  cin>>T;
  while(T--){
    cin>>s;
    manyChefs(s);
    cout<<s<<endl;
  }
}
