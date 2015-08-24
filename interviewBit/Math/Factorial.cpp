/* Given an integer n, return the number of trailing zeroes in n!. */
int Solution::trailingZeroes(int A) {
    int n=5;
    int count=0;
    while((int)A/n>0){
        count+=(int)A/n;
        n=n*5;
    }
    return count;
}
