/*
 *Given a positive integer which fits in a 32 bit signed integer,
 *find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.
 */

bool Solution::isPower(int A) {
    int i,j;
    if(A==1)
        return 1;
    for(i=2;i<100000;i++){
        j=i;
       while(j<=INT_MAX/i){
           j=j*i;
           if(j==A)
            return 1;
       }
    }
    return 0;
}
