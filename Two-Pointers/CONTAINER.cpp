/*
 *Given n non-negative integers a1, a2, ..., an,
 *where each represents a point at coordinate (i, ai).
 *'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 *Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *Your program should return an integer which corresponds to the maximum area of water that can be contained
 *( Yes, we know maximum area instead of maximum volume sounds weird. But this is 2D plane we are working with for simplicity ).
 *[1, 5, 4, 3]==> 6
 */
int Solution::maxArea(vector<int> &A) {
    int n=A.size();
    int p=0,q=n-1;
    int maxA=0;
    while(p<q){
        maxA=max(maxA,(min(A[p],A[q])*(q-p)));
        if(A[p]<A[q])
            p++;
        else q--;
    }
    return maxA;
}
