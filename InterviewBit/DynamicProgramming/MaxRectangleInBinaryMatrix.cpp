
int Solution::maximalRectangle(vector<vector<int> > &A) {
    int i,j,c;
    int m=A.size();
    int n=A[0].size();
    int C[m][m];
    int maxArea=0;
    int NC[m][m];
    memset(C,0,sizeof(C));
   
    for(c=0;c<n;c++){
        memset(NC,0,sizeof(C));
        // construct new column from vector A
        for(i=0;i<m;i++){
            for(j=i;j<m;j++){
                if(A[j][c]==0)
                    break;
                else NC[i][j]=1;
            }
        }
        // merge column operation
        for(i=0;i<m;i++)
            for(j=i;j<m;j++){
                C[i][j]=C[i][j]*NC[i][j]+NC[i][j];
                maxArea=max(maxArea,(j-i+1)*C[i][j]);
            }
    }
    return maxArea;
}
