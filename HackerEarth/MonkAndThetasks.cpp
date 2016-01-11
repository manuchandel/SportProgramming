#include <bits/stdc++.h>
using namespace std;

int ones(long long A){
	int count=0;
	while(A>0){
		if(A&1)
			count++;
		A=A>>1;
	}
	return count;
}

int main()
{
    int T,N,i,j;
    long long A;
    scanf("%d",&T);
    vector< vector<long long> >v;
    vector <long long> row;
    for(i=0;i<64;i++)
    	v.push_back(row);

    while(T--){
    	scanf("%d",&N);
    	for(i=0;i<N;i++){
    		scanf("%lld",&A);
    		v[ones(A)].push_back(A);
    	}
    	for(i=0;i<64;i++){
    		for(j=0;j<v[i].size();j++)
    			printf("%lld ",v[i][j]);
    	}
    	printf("\n");
    	for(i=0;i<64;i++)
    		v[i].clear();
    }
    
}
