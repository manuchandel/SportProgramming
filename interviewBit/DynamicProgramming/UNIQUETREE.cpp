int Solution::numTrees(int A) {
    int B[A+1],i,j;
    for(i=0;i<A+1;i++)
        B[i]=0;
    B[0]=1;
    for(i=1;i<=A;i++)
    for(j=i;j>0;j--)
        B[i]+=B[j-1]*B[i-j];
    return B[A];
}
