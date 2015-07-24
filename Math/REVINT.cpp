/* Reverse a Given int if the result overflows return 0 */

int Solution::reverse(int A) {
    bool negative=0;
    if(A<0){
        negative=1;
        A=A*(-1);
    }
    int tenPow[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    int i=0;
    int noOfDigits=0;
    while(i<10 && A/tenPow[i]>0) i++;
    noOfDigits=i;
    if(noOfDigits==1){
        if(negative)
            A*=-1;
        return A;
    }
    long long B=A, C=0,temp;
    for(i=0;i<noOfDigits;i++){
        temp=B%10;
        B/=10;
        C+=temp*tenPow[noOfDigits-1-i];
    }
    if(negative)
        C*=-1;
    if(C>INT_MAX || C< INT_MIN)
        return 0;
    return (int)C;
    
}
