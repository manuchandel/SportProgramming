#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define max 1000001
#define base 3
using namespace std;
ll *one=new ll[max];
ll pow1(ll a,ll b){
	ll x=1;
	ll y=a;
	while(b>0){

		if(b&1){
			//cout<<x<<endl;
			x=x*y;
			x%=mod;
		}
		b=b>>1;
		y=y*y;
		y%=mod;
	}
	//cout<<x<<endl;
	return x;
}
bool check(char *s,int p,int q,int a){
	int i;
	for(i=0;i<q;i++){
		if(s[i+p]!=s[i+a])
			return false;
	}
	return true;
}
ll inv;
bool check(char *s,int l,int n){

	unordered_map<ll,vector<int> > m;
	int p=0;
	int q=l-1;
	int i=0;
	ll hash=0;
	hash%=mod;
	for(i=0;i<l;i++){
		hash+=(s[i]-'a'+1)*one[i];
		hash%=mod;
	}
	m[hash].push_back(0);
	p=0;q=l;
	while(q<n){
		
		ll new_hash=hash-(s[p]-'a'+1);
		if(new_hash<0)
			new_hash+=mod;
		//cout<<new_hash<<endl;
		new_hash=new_hash*inv;
		new_hash%=mod;
		//cout<<new_hash<<endl;
		ll temp=(s[q]-'a'+1)*one[l-1];
		temp%=mod;
		new_hash+=temp;
		//cout<<new_hash<<endl;
		new_hash%=mod;
		hash=new_hash;
		
		if(m.find(hash)!=m.end()){
			//cout<<temp<<endl;
			int x=m[hash].size();
			for(i=0;i<x;i++){
				if(check(s,m[hash][i],l,p+1))
					return true;
				m[hash].push_back(p+1);
			}
			
		}else m[hash].push_back(p+1);
		p++;q++;
	}
	return false;
}

int main()
{
	inv=pow1(base,mod-2);
    char *buff=new char[1000001];
    scanf("%s",buff);
    int i;
    int n=strlen(buff);
 
    one[0]=1;
    for(i=1;i<max;i++){
    	one[i]=base*one[i-1];
    	one[i]%=mod;
    }

    int l=1;
    int r=n;
    int ans=0;
    while(l<=r){
    	int mid=(l+r)>>1;
    	if(check(buff,mid,n)){
    		ans=mid;
    		l=mid+1;
    	}else r=mid-1;
    }
    printf("%d\n",ans);
}
