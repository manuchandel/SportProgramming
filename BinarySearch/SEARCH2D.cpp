/*
 *Write an efficient algorithm that searches for a value in an m x n matrix.
 *This matrix has the following properties
 *Integers in each row are sorted from left to right.
 *The first integer of each row is greater than or equal to the last integer of the previous row.
 */

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int m=A.size();
    int n=A[0].size();
    int searchRow=-1;
    int l=0,r=n-1,mid;
    int i,j;
    if(B<A[0][0] || B> A[m-1][n-1])
        return 0;
    l=0; r=m-1;
    /* search the fittest row */
    while(l<=r){
        mid=(l+r)>>1;
        if(A[mid][0]==B)
            return 1;
        else if(A[mid][0]<B)
            l=mid+1;
        else r=mid-1;
    }
    searchRow=r;
    l=0,r=n-1;
    /* search in the given row*/
    while(l<=r){
        mid=(l+r)>>1;
        if(A[searchRow][mid]==B)
            return 1;
        else if(A[searchRow][mid]<B)
            l=mid+1;
        else r=mid-1;
    }
    return 0;
}
