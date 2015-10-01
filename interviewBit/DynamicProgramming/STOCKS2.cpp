int Solution::maxProfit(const vector<int> &A) {
    int n=A.size();
    if(n==0)
        return 0;
    int i;
    int investment=A[0];
    int profit=0;
    for(i=1;i<n;i++){
        if(investment<A[i]){
            profit+=A[i]-investment;
        }
        investment=A[i];
    }
    return profit;
}
