#include <bits/stdc++.h>
#define MAX 3000
#define mod 100000007
#define ll long long
#define ini(x) scanf("%d",&x)
#define inl(x) scanf("%lld",&x)
#define ind(x) scanf("%lf",&x)
#define type double
using namespace std;
char arr[1000001];
char palin[1000001];
int add1(string s){
  int n=s.length();
  int i;
  int sum=0;
  int carry=1;
  for(i=0;i<n;i++){
    sum=s[n-1-i]-'0'+carry;
    if(sum<=9){
      arr[i]=sum+'0';
      carry=0;
    }else{
      int digit=sum%10;
      arr[i]=digit+'0';
      carry=1;
    }
  }
  if(carry==1){
    arr[n]=1+'0';
    n++;
  }
  for(i=0;i<n/2;i++){
    swap(arr[i],arr[n-1-i]);
  }
  return n;
}
bool ispalin(int n){
  int i;
  for(i=0;i<n;i++){
    if(arr[i]!=arr[n-1-i])
      return false;
  }
  return true;
}
bool nextPalin(int p,int q, bool flag){
    if(p>q)
      return flag;
    if(p==q){
      if(flag)
        return 1;
      else {
        if(arr[p]=='9'){
          arr[p]='0';
          return 0;
        }
        else{
          arr[p]=arr[p]+1;
          return 1;
        }
      }
    }

    if(arr[p]>arr[q]){
      arr[q]=arr[p];
      nextPalin(p+1,q-1,1);
    }else if(arr[p]==arr[q]){
      bool b=nextPalin(p+1,q-1,flag);
      if(!b){
        if(arr[p]=='9'){
          arr[p]='0';
          arr[q]='0';
          return 0;
        }
          
        arr[p]=arr[p]+1;
        arr[q]=arr[p];
      }
    }else{
      bool b=nextPalin(p+1,q-1,0);
      if(b){
        arr[q]=arr[p];
      }else{
        arr[p]=arr[p]+1;
        arr[q]=arr[p];
      }
    }
    return 1;
   
}

int main(){
  int t,i;
  int n;
  ini(t);
  while(t--){
    string s;
    cin>>s;
    n=add1(s);
    if(!ispalin(n))
      nextPalin(0,n-1,0);
    for(i=0;i<n;i++){
      printf("%c",arr[i] );
    }
    printf("\n");
  }
}
