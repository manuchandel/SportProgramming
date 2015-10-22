#include <stdio.h>
#include <iostream>
using namespace std;
int *a=new int[6101];
int *b=new int[6101];
int min(int a,int b){
	if(a<b)
		return a;
	return b;
}
int palindrome(string s,int n){
	int i,j,k,*c;
	for(i=0;i<n;i++){
		a[i]=0;
		b[i]=0;
	}
	for(j=1;j<n;j++){
		k=j;
		for(i=0;i<n-j;i++){
			if(s[i]==s[k]){
				b[i]=b[i+1];
			}else{
				b[i]=1+min(a[i],a[i+1]);
			}
			k++;
		}
		c=a;
		a=b;
		b=c;
	}
	return a[0];
}
int main(){
	int T;
	string s;
	scanf("%d",&T);
	while(T--){
		cin>>s;
		printf("%d\n",palindrome(s,s.length()));
	}

}
