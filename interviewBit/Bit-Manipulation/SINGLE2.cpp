/*
 *Given an array of integers, every element appears thrice except for one which occurs once.
 *Find that element which does not appear thrice.
 *Note: Your algorithm should have a linear runtime complexity.
 *Could you implement it without using extra memory?
 */
 
 /*
  *construct a number bit by bit
  *At ith position there will be 3x times 1 and 3x times zero and 1 (0 or 1) of the number whih appears once
  */


int Solution::singleNumber(const vector<int> &A) {
    int i,j;
    int n=A.size();
    int evenCount=0,oddCount=0;
    int ans=0,bit=0,place=1;
    for(i=0;i<32;i++){
        bit=0;
        evenCount=0;
        oddCount=0;
        for(j=0;j<n;j++){
            if(A[j]&place)
                oddCount++;
            else evenCount++;
        }
        if(oddCount%3==0)
            bit=0;
        else bit=1;
        bit=bit<<i;
        ans=ans | bit;
        place=place<<1;
    }
    return ans;
}
