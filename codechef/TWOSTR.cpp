#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string.h>
#define FOR(a,b) for(int a=0;a<b;a++)
using namespace std;
bool check(string s1,string s2){
  int i=0;
  int n=s1.length();
  for(i=0;i<n;i++){
    if(s1[i]!=s2[i]){
      if(s1[i]!='?' && s2[i]!='?')
        return 0;
    }
  }
  return 1;
}
 
int main()
{
  int T;
  scanf("%d",&T);
  string s1,s2;
  while(T--){
    cin>>s1>>s2;
    if(check(s1,s2))
      printf("Yes\n");
    else printf("No\n");
  }
} 
