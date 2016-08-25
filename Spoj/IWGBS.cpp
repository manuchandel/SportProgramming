#include <bits/stdc++.h>
#define MAX 100001
#define ll long long
using namespace std;

string add(string a,string b){

    int n1=a.length();
    int n2=b.length();
    int carry=0;
    int i;
    string c="";
    for(i=0;i<min(n1,n2);i++){
        int sum=a[i]-'0'+b[i]-'0'+carry;
        int dig=sum%10;
        carry=sum/10;
        c+=(dig+'0');
    }
    while(i<n1){
        int sum=a[i]-'0'+carry;
        c+=(sum%10+'0');
        carry=sum/10;
        i++;
    }
    while(i<n2){
        int sum=b[i]-'0'+carry;
        c+=(sum%10+'0');
        carry=sum/10;
        i++;
    }
    if(carry>0)
        c+=(carry+'0');
    return c;
}

int main(){
    int i,j;
    string arr[10001];
    arr[0]="0";
    arr[1]="2";
    arr[2]="3";
    for(i=3;i<10001;i++)
        arr[i]=add(arr[i-1],arr[i-2]);

    for(i=0;i<10001;i++){
        int n=arr[i].length();
        for(j=0;j<n/2;j++)
            swap(arr[i][j],arr[i][n-j-1]);
    }
    int n;
    cin>>n;
    cout<<arr[n]<<endl;
}
