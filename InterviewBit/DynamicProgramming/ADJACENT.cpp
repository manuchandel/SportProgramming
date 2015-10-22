int Solution::adjacent(vector<vector<int> > &A) {
    int n=A[0].size();
    int B[n+1];
    int i,ans,maxi=0;
    for(i=0;i<=n;i++)
        B[i]=0;
    B[n-1]=max(A[0][n-1],A[1][n-1]);
    ans=B[n-1];
    for(i=n-2;i>=0;i--){
        maxi=max(B[i+2],maxi);
        B[i]=max(A[0][i],A[1][i])+maxi;
        ans=max(ans,B[i]);
    }
    return ans;
}
