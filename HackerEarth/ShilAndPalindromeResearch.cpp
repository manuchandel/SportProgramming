#include <bits/stdc++.h>
#define IN(L) scanf("%d",&L)
#define mod 1000000007
#define MAX 100001
#define ll long long
using namespace std;

class Bit{
	public:
		int *arr;
		Bit(){
			arr=new int[MAX];
			memset(arr,0,sizeof(int)*MAX);
			
		}
		void update(int x,int y){
			int index=x+1;
			while(index<MAX){
				arr[index]+=y;
				index+=(index&(-index));
			}
		}
		int query(int x, int y){
			int l=x;
			int r=y+1;
			int index=0;
			int lans=0;
			int rans=0;

			index=l;
			while(index>0){
				lans+=arr[index];
				index=index-(index&(-index));
			}

			index=r;
			while(index>0){
				rans+=arr[index];
				index=index-(index&(-index));
			}

			return rans-lans;
		}
};
int main(){
	
	int N,Q,i;
	
	Bit A[26];
	IN(N);IN(Q);
	char s[N+1];
	scanf(" %s",s);
	for(i=0;i<N;i++)
		A[s[i]-'a'].update(i,1);

	while(Q--){
		char c;
		int type;
		int x,y;
		IN(type);
		if(type==1){
			IN(x);
			scanf(" %c",&c);
			char prev=s[x-1];
			s[x-1]=c;
			A[c-'a'].update(x-1,1);
			A[prev-'a'].update(x-1,-1);

		}else{
			IN(x);IN(y);
			bool flag=true;
			int allowed=0;
			for(i=0;i<=25;i++){
				int ans=A[i].query(x-1,y-1);
				if(ans<0){
					printf("Wrong calculation\n");
				}
				if(ans&1)
					allowed+=1;
				if(allowed>1){
					flag=false;
					break;
				}
			}
			if(flag)
				printf("yes\n");
			else printf("no\n");
		}

	}
}
	
