#include <bits/stdc++.h>
#define IN(L) scanf("%d",&L)
#define mod 1000000007
#define MAX 100001
#define ll long long
using namespace std;
int *A=new int[1000000];
char *buf=new char[1000000];
void compute(int n){
	int i=1,j=0;
	A[0]=0;
	while(i<n){
		if(buf[j]==buf[i]){
			A[i]=j+1;
			i++;j++;

		}else if(j==0){
			A[i]=0;
			i++;
		}else{
			j=A[j-1];
		}
	}
}
void match(int n){
	int i=0,j=0;
	bool gt=false;
	char c;
	//printf("%s\n",buf );
	c=getchar();
	//printf("c = %c\n",c );
	while(c!='\n'){
		//printf("c = %c\n",c );
		//printf("%d %d\n",n,j );
		if(c==buf[j]){
			j++;
			i++;
			c=getchar();
		}
		else if(j==0){
			i++;
			c=getchar();
		}
		else j=A[j-1];
		

		if(j==n){
			printf("%d\n",i-n);
			j=A[j-1];
			gt=true;
			//printf("j %d\n",j );
		}
		
	}
	printf("\n");
	if(!gt)
		printf("\n");
}
int main(){
	int N,n;
	IN(n);
	while(IN(n)!=EOF){
		scanf(" %s",buf);
		getchar();
		compute(n);
		match(n);
	}
	
}
