int Solution::minPathSum(vector<vector<int> > &A) {
    int m=A.size();
    int n=A[0].size();
    int i,j;
    vector<int> v(n,0);
    v[n-1]=A[m-1][n-1];
    for(i=n-2;i>=0;i--)
        v[i]=v[i+1]+A[m-1][i];
    for(i=m-2;i>=0;i--){
        v[n-1]+=A[i][n-1];
        for(j=n-2;j>=0;j--)
            v[j]=A[i][j]+min(v[j],v[j+1]);
    }
    return v[0];
}
