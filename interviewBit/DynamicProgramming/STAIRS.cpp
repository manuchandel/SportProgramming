int Solution::climbStairs(int A) {
    if(A==1)
        return 1;
    if(A==2)
        return 2;
    int p=2;
    int q=1;
    int i=2;
    int ans=0;
    while(i<A){
        ans=p+q;
        q=p;
        p=ans;
        i++;
    }
    return ans;
}
