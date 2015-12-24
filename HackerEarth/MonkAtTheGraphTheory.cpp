#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,i;
	int degree=0,degree_count=0;
	bool flag=1;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&degree);
		if(degree==0)
			flag=0;
		degree_count+=degree;
	}

	if((degree_count>>1)==N-1 && flag)
		printf("Yes\n");
	else printf("No\n");
	
}