/*
 *Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.
 *Time O(n^2) & extra space O(1)
 */

/*
 *g++ -std=c++11 filename
 */
#include <iostream>
#include <vector>
#define IN(x) cin>>x
#define OUT(x) cout<<x
using namespace std;
int fillup(vector<vector<int>>& v,int n,int startrow,int startcol,int num){
	int i;	//loop variable
	/* go right */
	for(i=0;i<n;i++){
		v[startrow][i+startcol]=num;
		num++;
	}
	/* go down */
	for(i=1;i<n;i++){
		v[startrow+i][startcol+n-1]=num;
		num++;
	}
	/* go left */
	for(i=0;i<n-1;i++){
		v[startrow+n-1][startcol+n-2-i]=num;
		num++;
	}
	/* come up */
	for(i=0;i<n-2;i++){
		v[startrow+n-2-i][startcol]=num;
		num++;
	}
	return num;


}
/* function to return matrix in spiral order */
vector<vector<int>> fill(int n){
	vector<int> v1(n,0);
	vector<vector<int>> v(n,v1);
	int num=1;
	for(int i=0;i<=n/2;i++)
		num=fillup(v,n-2*i,i,i,num);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			OUT(v[i][j]<<" ");
		OUT(endl);
	}
	return v;
}
int main(){
	int n;	//no of elements
	IN(n);	//input n
	fill(n);
}
