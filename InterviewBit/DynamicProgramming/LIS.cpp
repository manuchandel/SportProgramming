int Solution::lis(const vector<int> &A) {
    int n=A.size(),i,j;
    set<int> myset;
    myset.insert(A.begin(),A.end());
    vector<int> B;
    for(auto it=myset.begin();it!=myset.end();++it)
        B.push_back(*it);
    int m=B.size();
    vector< int > v(n,0);
    
    if(A[0]==B[0])
        v[0]=1;
    for(i=1;i<n;i++){
        if(A[i]==B[0])
            v[i]=1;
        else v[i]=v[i-1];
    }
    int diagonal;
    for(i=1;i<m;i++){
        diagonal=v[0];
        if(A[0]==B[i])
            v[0]=1;
        for(j=1;j<n;j++){
            int temp=v[j];
            if(A[j]==B[i]){
                v[j]=1+diagonal;
            }else v[j]=max(v[j],v[j-1]);
            diagonal=temp;
        }
    }
    return v[n-1];
}
