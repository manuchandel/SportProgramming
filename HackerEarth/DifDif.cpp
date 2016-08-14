#include <bits/stdc++.h>
#define IN(L) scanf("%d",&L)
#define mod 1000003
#define MAX 100001
#define ll long long
using namespace std;


int main(){

	string s;
	cin>>s;
	set<string> se;
	for(int i=1;i<=s.length();i++){
		int p=0;
		int q=i-1;
		while(q<s.length()){
			se.insert(s.substr(p,i));
			p++;q++;
		}
		
	}
	printf("%d\n",(int)se.size());
	
}
