int Solution::numDistinct(string S, string T) {
    int i,j,k;
    int n=T.length();
    i=S.length()-1;
    while(S[i]!=T[n-1] && i>=0) i--;
    if(i<0)
        return 0;
    S=S.substr(0,i+1);
    int m=S.length();
    int A[m][n];
    memset(A,0,sizeof(A));
    A[m-1][n-1]=1;
    for(i=m-2;i>=0;i--){
        k=m-i;
        for(j=n-1;j>=0 && k;j--){
            if(S[i]==T[j]){
                if(j==n-1)
                    A[i][j]=1+A[i+1][j];
                else A[i][j]=A[i+1][j+1]+A[i+1][j];
            }
            else A[i][j]=A[i+1][j];
            k--;
        }
    }
    return A[0][0];
}
