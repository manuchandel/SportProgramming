int Solution::canJump(vector<int> &A) {
    int i,n=A.size(),d=n-1,jump=1;
    i=n-2;
    while(i>=0){
        jump=d-i;
        if(A[i]>=jump){
            d=i;
        }
        i--;
    }
    if(d==0)
        return 1;
    return 0;
}
