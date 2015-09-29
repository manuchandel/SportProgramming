
int Solution::jump(vector<int> &A) {
    int i,n=A.size();
    if(n==1)
        return 0;
    int steps=1;
    int currentMaxReachable=A[0];
    int maxReachable=A[0];
    for(i=0;i<=maxReachable;i++){
        if(i==n-1)
            return steps;
        currentMaxReachable=max(currentMaxReachable,i+A[i]);
        if(i==maxReachable){
            if(currentMaxReachable<=i)
                return -1;
            maxReachable=currentMaxReachable;
            steps++;
        }
    }
    return -1;
}
