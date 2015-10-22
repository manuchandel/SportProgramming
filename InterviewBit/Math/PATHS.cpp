/*
 *The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).
 *How many possible unique paths are there?
 *Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.
 */
 
/*** Ans= (A+B-2)!/[(A-1)! *(B-1)!]**/
int Solution::uniquePaths(int A, int B) {
    int bigger=A-1;
    int smaller=B-1;
    if(B>A){
        bigger=B-1;
        smaller=A-1;
    }
    if(smaller==0)
        return 1;
    long long ans=1;
    int i;
    for(i=0;i<smaller;i++){
        ans=ans*(bigger+smaller-i);
        ans=ans/(i+1);
    }
    return (int)ans;
    
}
