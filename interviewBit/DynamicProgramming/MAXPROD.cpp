int B(vector<int> A){
    int i,j,n=A.size();
    if(n==1)
        return A[0];
    long long k=A[0];
    for(i=1;i<n;i++)
        k*=A[i];
    if(k>0)
        return k;
    long long l=1,r=1;
    i=0;
    while(A[i]>0){
        l*=A[i];
        i++;
    }
    l*=A[i];
    i=n-1;
    while(A[i]>0){
        r*=A[i];
        i--;
    }
    r*=A[i];
    return (int)max(k/l,k/r);
}
int Solution::maxProduct(const vector<int> &A) {
    int ans=A[0],j=A[0];
    vector<int> v;
    int i;
    for(i=0;i<A.size();i++){
        if(A[i]!=0)
            v.push_back(A[i]);
        else{
            j=0;
            if(v.size()>0)
                ans=max(ans,B(v));
            v.clear();
        }
    }
    if(v.size()>0)
        ans=max(ans,B(v));
    return max(ans,j);

}
