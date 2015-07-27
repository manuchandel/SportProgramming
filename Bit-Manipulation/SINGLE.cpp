/*
 *Given an array of integers, every element appears twice except for one. Find that single one.
 */

int Solution::singleNumber(const vector<int> &A) {
    int i;
    int n=A.size();
    int ans=0;
    for(i=0;i<n;i++)
        ans=ans^A[i];
    return ans;
}
