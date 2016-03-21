int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int i,j;
    int m=A.size();
    int n=A[0].size();
    vector<vector<int>> v;
    for(i=0;i<m;i++){
        vector<int> r(n,0);
        v.push_back(r);
    }
    if(A[m-1][n-1]>=0)
        v[m-1][n-1]=0;
    else v[m-1][n-1]=abs(A[m-1][n-1]);
    for(i=n-2;i>=0;i--){
        if(A[m-1][i]<=0)
            v[m-1][i]=abs(A[m-1][i])+v[m-1][i+1];
        else {
            if(A[m-1][i]>=v[m-1][i+1])
                v[m-1][i]=0;
            else v[m-1][i]=v[m-1][i+1]-A[m-1][i];
        }
    }
    for(i=m-2;i>=0;i--){
        if(A[i][n-1]<=0)
            v[i][n-1]=abs(A[i][n-1])+v[i+1][n-1];
        else {
            if(A[i][n-1]>=v[i+1][n-1])
                v[i][n-1]=0;
            else v[i][n-1]=v[i+1][n-1]-A[i][n-1];
        }
        for(j=n-2;j>=0;j--){
            if(A[i][j]<=0)
                v[i][j]=abs(A[i][j])+min(v[i+1][j],v[i][j+1]);
            else {
                if(A[i][j]>=min(v[i+1][j],v[i][j+1]))
                    v[i][j]=0;
                else v[i][j]=min(v[i+1][j],v[i][j+1])-A[i][j];
            }
        }
    }
    return v[0][0]+1;
}
