/*
 *Rotate a 2D matrix by 90 degree without extra space
 */
#include <iostream>
#include <vector>
#define IN(a) cin>>a
#define OUT(a) cout<<a 
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
void swap(int& a,int &b){
	int c=a;
	a=b;
	b=c;
}
/* rotates the boundary of nxn matrix by 90 degree */
void utility(vector<vector<int> > &v,int startRow,int startCol,int n){
	int i;
	for(i=0;i<n/2;i++)  //reverse first row
		swap(v[startRow][startCol+i],v[startRow][startCol+n-1-i]);
		
	for(i=0;i<n/2;i++)  //reverse last row
		swap(v[startRow+n-1][startCol+i],v[startRow+n-1][startCol+n-1-i]);
		
	for(i=0;i<n;i++)  //swap elements of first row right-left with last column down-top
		swap(v[startRow][startCol+i],v[startRow+n-1-i][startCol+n-1]);
		
	for(i=0;i<n;i++)  //swap elements of first column top-down with last row right-left
		swap(v[startRow+i][startCol],v[startRow+n-1][startCol+n-1-i]);
		
	/* swap first element of first row with last element of last row */
	swap(v[startRow][startCol],v[startRow+n-1][startCol+n-1]);
	
	for(i=1;i<n-1;i++)  //swap elements of first row and last row left-right except first and last element
		swap(v[startRow][startCol+i],v[startRow+n-1][startCol+i]);
}
void rotate(vector<vector<int> > &A) {
	int n=A.size();
	for(int i=0;i<n/2;i++)
		utility(A,i,i,n-2*i); //call iteratively for all outer boundaries
}
	
int main(){
	int n;	// no of elements in given array
	IN(n);
	vector<int> v1(n,0);
	vector< vector<int> > v(n,v1);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			IN(v[i][j]);
	/* print before rotation */
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			OUT(v[i][j]<<" ");
		OUT(endl);
	}
	rotate(v);
	OUT(endl);OUT(endl);
	/* print after rotation */
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			OUT(v[i][j]<<" ");
		OUT(endl);
	}
}
