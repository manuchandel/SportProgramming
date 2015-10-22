#include <cstdio>
#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	int T,N,i,k,j,l=21;
	string A[10];
	cin>>T;
	string s,ans="",temp;
	bool present;
	while(T--){
		l=21;
		cin>>N;
		ans="";
		for(i=0;i<N;i++){
			cin>>A[i];
			if(A[i].length()<l){
				l=A[i].length();
				temp=A[i];
			}
		}
		for(i=temp.length();i>0;i--){
			for(j=0;j<temp.length()-i+1;j++){
				s=temp.substr(j,i);
				present=1;
				for(k=0;k<N && present;k++){
					if(A[k].find(s)==string::npos)
						present=0;
				}
				if(present){
					if(s.length()>ans.length())
						ans=s;
					else if(s.length()==ans.length() && s<ans)
						ans=s;
				}
			}
			if(ans.length()>0)
				break;
		}
		cout<<ans<<endl;
	}
}

