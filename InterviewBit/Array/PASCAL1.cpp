/*
 *Given numRows, generate the first numRows of Pascal’s triangle.
 *Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1
 *time=O(n^2) space=O(1) no additional space
 */
#include <cstdio>
#include <vector>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;

vector<vector<int>> function(int n){
	if(n==0){
        vector<vector<int>> v2;
        return v2;
    }
    vector<int> v1(n,0);
	vector<vector<int>> v(n,v1);
	v[0][0]=1;
	for(int i=1;i<n;i++){
		v[i][0]=1;
		for(int j=1;j<i;j++)
			v[i][j]=v[i-1][j]+v[i-1][j-1];
		v[i][i]=1;
	}
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
			v[i].pop_back();
	for(int i=0;i<n;i++){
		for(int j=0;j<v[i].size();j++)
			printf("%d ",v[i][j] );
		printf("\n");
	}
	return v;
}
	
int main(){
	int n;	// no of elements in given array
	int i;	// loop variable
	IN(n);
	function(n);
}
