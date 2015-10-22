#include <bits/stdc++.h>
using namespace std;
void sieve(bool *A){
	for(int i=0;i<10000001;i++)
		A[i]=true;
	A[10000001]=1;
	for(int i=2;i<3163;i++)
		for(int j=i*i;j<=10000000 && A[i];j+=i)
			A[j]=false;
}
int main()
{
	int n,x;
	bool *A=new bool[10000001];
	sieve(A);
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		if(A[x])
			printf("NO\n");
		else{
			if(((int)sqrt(x))*((int)sqrt(x))==x && A[(int)sqrt(x)])
				printf("NO\n");
			else printf("YES\n");
		}
	}
    return 0;
}

