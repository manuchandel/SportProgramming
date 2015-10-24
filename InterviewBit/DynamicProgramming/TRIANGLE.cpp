int Solution::minimumTotal(vector<vector<int> > &A) {
    int i,j,n=A.size();
    for(i=n-2;i>=0;i--){
        for(j=0;j<A[i].size();j++){
            A[n-1][j]=A[i][j]+min(A[n-1][j],A[n-1][j+1]);
        }
    }
    return A[n-1][0];
}

