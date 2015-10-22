int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int i,ans=INT_MIN;
    for(i=0;i<A.size();i++){
        ans=max(ans,abs(A[i]-B[i]));
    }
    return ans;
}
