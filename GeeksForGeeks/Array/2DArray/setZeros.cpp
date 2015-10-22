/*
 *Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.
 *Time O(n^2) & Space O(1)
 */

/*
 *1 0 0     0 0 0
 *1 1 1 ==> 1 0 0
 *1 1 1     1 0 0
 */

/*
 *determine the first zero row i.e first element which is zero
 *now this row will act as a extra space to store column numbers which are to be made zero
 *invert the elements of firstZeroRow
 *start from row i+1 whenever u element zero mark its column 1 in firstZeroRow and after u finish traversing row if any element was found zero than make row zero
 *At last traverse firstZeroRow and make all columns zero who has value 1 in firstZeroRow
 *AT the end make all elements of firstZeroRow zero
 */
#include <iostream>
#include <vector>
#define IN(a) cin>>a
#define OUT(a) cout<<a 
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
int firstZeroRow(vector< vector<int> > &A,int m,int n){
	int i,j;
	FOR(i,m)
		FOR(j,n)
			if(A[i][j]==0)
				return i;
	return -1;
}
void setZeroes(vector< vector<int> > &A) {
	int i,j;
	int n=A[0].size();
	int m=A.size();
	int fzr=firstZeroRow(A,m,n);
	if(fzr<0)
		return;
	bool row;
	/* invert elements of first zero row */
	FOR(i,n)
		A[fzr][i]=1-A[fzr][i];
	for(i=fzr+1;i<m;i++){
		row=0;
		FOR(j,n){
			if(A[i][j]==0){
				row=1;
				A[fzr][j]=1;
			}
		}
		if(row)
			FOR(j,n)
				A[i][j]=0;
	}
	/* make correspoding column zero */
	FOR(i,n){
		if(A[fzr][i]==1){
			FOR(j,m)
				A[j][i]=0;
		}
	}
	/* make fzr O*/
	FOR(i,n)
		A[fzr][i]=0;
}

int main(){
	int n,m;	// no of elements in given array
	int i,j;
	IN(m);
	IN(n);
	vector<int> v1(n,0);
	vector< vector<int> > v(m,v1);
	FOR(i,m)
		FOR(j,n)
			IN(v[i][j]);
	setZeroes(v);
	OUT(endl);
	FOR(i,m){
		FOR(j,n)
			OUT(v[i][j]<<" ");
		OUT(endl);
	}
}
