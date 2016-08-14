#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s,string t){
	int k=0;
	for(int i=0;i<t.length();i++){
		if(s[k]==t[i])
			k++;
		if(k==s.length())
			return true;
	}
	return false;
}
int main()
{
	int i;
	string s,t;
	cin>>s;
	cin>>t;
	int n=t.length();
	int l=1,r=s.length();
	int ans=0;
	while(l<=r){
	 	int mid=(l+r)>>1;
	 	//cout<<l<<" "<<r<<" "<<mid<<endl;
	   	if(isSubsequence(s.substr(0,mid),t)){
	   		ans=mid;
	   		l=mid+1;
	   	}else r=mid-1;
	   	//cout<<l<<" "<<r<<" "<<mid<<endl;
	}
	printf("%d\n",ans );

}
