#include <bits/stdc++.h>
#define IN(L) scanf("%d",&L)
#define mod 1000000007
#define MAX 100001
#define ll long long
using namespace std;
int bit[100001];
struct Q{
	int l;int r;int i;
};
bool comp(Q a, Q b){
	return a.r<b.r;
}
void update(int x,int y){
	int i=x+1;
	while(i<MAX){
		bit[i]+=y;
		i=i+(i&(-i));
	}
}

int find(int l, int r){
	int lans=0;
	int rans=0;
	int i=l;
	while(i>0){
		lans+=bit[i];
		i=i-(i&(-i));
	}
	i=r+1;
	while(i>0){
		rans+=bit[i];
		i=i-(i&(-i));
	}
	return rans-lans;
}
int main(){
	int n,m,D,i,j,k=0;
	int arr[MAX];
	int ans[MAX];
	int index[MAX+10];
	memset(bit,0,sizeof(bit));
	memset(index,-1,sizeof(index));
	IN(n);IN(m);IN(D);
	for(i=0;i<n;i++){
		IN(arr[i]);
		index[arr[i]]=i;
	}
	Q query[m];
	for(i=0;i<m;i++){
		IN(query[i].l);IN(query[i].r);
		query[i].i=i;
		query[i].l-=1;
		query[i].r-=1;
	}
	sort(query,query+m,comp);
	for(i=0;i<n;i++){
		update(i,1);
		for(j=1;j<=D;j++){

			int desired=arr[i]+j;
			if(index[desired]>=0){
				int ind=index[desired];
				if(ind<=i){
					update(ind,1);
				}
			}
			desired=arr[i]-j;
			if(desired>0 and index[desired]>=0 ){
				int ind=index[desired];
				if(ind<=i){
					update(ind,1);
				}
			}
		}
		while(k<m && query[k].r==i){
			ans[query[k].i]=find(query[k].l,MAX);
			k++;
		}
	}

	for(i=0;i<m;i++)
		printf("%d\n",ans[i]);
}
	
