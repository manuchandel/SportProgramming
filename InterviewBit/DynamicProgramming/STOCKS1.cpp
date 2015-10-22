int Solution::maxProfit(const vector<int> &A) {
    int min_so_far=INT_MAX;
    int diff=0;
    for(int i=0;i<A.size();i++){
        if(min_so_far>A[i])
            min_so_far=A[i];
        diff=max(diff,A[i]-min_so_far);
    }
    return diff;
}
