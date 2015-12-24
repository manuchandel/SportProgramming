#include <bits/stdc++.h>
#define FOR(i,a,b) for(i=a;i<b;i++)
using namespace std;
// sub is subsequence of s
bool checkSubSeq(string s, string sub){
	int i,j=0,n=s.length();
	FOR(i,0,n){
		if(s[i]==sub[j])
			j++;
		if(j==sub.length())
			return true;
	}
	return false;
}
int minCurse(string s, int n,string arr[]){
	int countS=s.length();
	int count=0,i;
	while(count!=n && countS>0 ){
		count=0;
		FOR(i,0,n){
			if(checkSubSeq(arr[i],s.substr(0,countS)))
				count++;
			else break;
		}
		if(count!=n)
			countS--;						
	}
	return countS;
}
int main(){
	int T,i,n,l,ans;
	scanf("%d",&T);
	string A,B;
	string arr[100];
	while(T--){
		A="";
		B="";
		scanf("%d",&n);
		FOR(i,0,n)
			cin>>arr[i];
		l=arr[0].length();
		FOR(i,0,l){
			A+='a';
			B+='b';
		}
		ans=min(minCurse(A,n,arr),minCurse(B,n,arr));
		printf("%d\n",ans);
	}
}