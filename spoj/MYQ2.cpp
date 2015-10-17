#include <cstdio>
#include <iostream>
#include <limits.h>
using namespace std;
int *arr=new int[1000001];
int *arrb=new int[1000001];
struct box{
	int start;
	int length;
};
int i;
int returnValue(char c){

	int v=(int)c;
	if(v>=65&&v<=90)
		v-=14;
	else if(v>=97&&v<=122)
		v-=96;
	else;
	//printf("%c %d\n",c,v);
	return v;
}
bool function(string s,int m,int k){
	int start=0,length=0,n=s.length(),j;
	arr[0]=returnValue(s[0])%m;
	arrb[0]=arr[0];
	if(arr[0]==k){
		length=1;
	}
	for(i=1;i<n;i++){
		arrb[i]=returnValue(s[i])%m;
		arr[i]=arrb[i]+arr[i-1];
		arr[i]%=m;
		if(arr[i]==k)
			length=i+1;
	}
	j=1;
	while(j<n){
		for(i=j+length;i<n;i++){
			//cout<<i<<" ";
			arr[i]=arr[i]-arrb[j-1];
			if(arr[i]<0)
				arr[i]+=m;
			arr[i]%=m;
			if(arr[i]==k){
				start=j;
				length=i-j+1;
			}//cout<<endl<<"j "<<j<<endl;
		}j++;
	}
	if(length==0)
		return false;
	printf("%d %d\n",start,length);
	return true;	
}
int main(){
	int T,m,k;
	scanf("%d",&T);
	string s;
	cin.ignore();
	while(T--){
		getline(cin,s);
		scanf("%d%d",&m,&k);
		if(!function(s,m,k))
			printf("-1\n");
		cin.ignore(INT_MAX,'\n');
		
	}
}
