int Solution::minDistance(string A, string B) {
    int i,j,k;
    int n=A.length();
    int m=B.length();
    int M[n+1];
    int del,rep,ins;
    for(i=0;i<=n;i++)
        M[n-i]=i;
    for(i=m-1;i>=0;i--){
        rep=M[n];
        M[n]+=1;
        for(j=n-1;j>=0;j--){
            del=M[j+1];
            ins=M[j];
            if(B[i]==A[j])
                M[j]=min(1+del,min(rep,1+ins));
            else M[j]=1+min(del,min(rep,ins));
            rep=ins;
        }
    }
    return M[0];
}
