/* You are given an n x n 2D matrix representing an image.
 *Rotate the image by 90 degrees (clockwise).
 *You need to do this in place.
 */

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
void Solution::rotate(vector<vector<int> > &A) {
    int n=A.size();
	for(int i=0;i<n/2;i++)
		utility(A,i,i,n-2*i); //call iteratively for all outer boundaries
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
