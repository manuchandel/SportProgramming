/*
 *Determine whether an integer is a palindrome. Do this without extra space.
 *A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
 *Negative numbers are not palindromic.
 */

bool Solution::isPalindrome(int A) {
     if(A<0)
        return false;
    int tenPow[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    int i=0;
    int noOfDigits=0;
    while(i<10 && A/tenPow[i]>0) i++;
    noOfDigits=i;
    if(noOfDigits==1)
        return true;
    int B=A;
    int C=0;
    int temp;
    for(i=0;i<noOfDigits;i++){
        temp=B%10;
        B/=10;
        C+=temp*tenPow[noOfDigits-1-i];
    }
    if(A==C)
        return true;
    return false;
    
    
}
