
int player1(int a,int b,vector<int> &v,int **M,vector<int> &sum);
int player2(int a,int b,vector<int> &v,int **M,vector<int> &sum);
int memoize(int a,int b,vector<int> &v,int **M,vector<int> &sum,int player){
    if(M[a][b]>0)
        return M[a][b];
    int oppprofit=0;
    if(player==1)
        oppprofit=player2(a,b,v,M,sum);
    else oppprofit=player1(a,b,v,M,sum);
    if(a==0)
        M[a][b]=sum[b]-oppprofit;
    else M[a][b]=sum[b]-sum[a-1]-oppprofit;
    return M[a][b];
}
int player1(int a,int b,vector<int> &v,int **M,vector<int> &sum){
    if(a==b)
        return v[a];
    int amount=max(v[a]+memoize(a+1,b,v,M,sum,1),v[b]+memoize(a,b-1,v,M,sum,1));
    return amount;
}
int player2(int a,int b,vector<int> &v,int **M,vector<int> &sum){
    if(a==b)
        return v[a];
    int amount=max(v[a]+memoize(a+1,b,v,M,sum,2),v[b]+memoize(a,b-1,v,M,sum,2));
    return amount;
}
int Solution::maxcoin(vector<int> &A) {
    int n=A.size(),i,j;
    int **M=new int *[n];
    for(i=0;i<n;i++)
        M[i]=new int[n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            M[i][j]=-1;
    vector<int> sum;
    sum.push_back(A[0]);
    for(i=1;i<n;i++)
        sum.push_back(A[i]+sum[i-1]);
    return player1(0,n-1,A,M,sum);
        
}

