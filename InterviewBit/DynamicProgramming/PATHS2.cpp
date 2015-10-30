int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int m=A.size();
    int n=A[0].size();
    int i,j;
    vector<int> v(n,0);
    if(A[m-1][n-1]==1)
        return 0;
    v[n-1]=1;
    for(i=n-2;i>=0;i--){
        if(A[m-1][i]==1)
            v[i]=0;
        else v[i]=v[i+1];
    }
    for(i=m-2;i>=0;i--){
        if(A[i][n-1]==1)
            v[n-1]=0;
        for(j=n-2;j>=0;j--){
            if(A[i][j]==1)
                v[j]=0;
            else v[j]+=v[j+1];
            
        }
    }
    return v[0];
}
