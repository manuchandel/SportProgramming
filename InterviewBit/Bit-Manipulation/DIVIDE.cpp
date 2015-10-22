/*
*Divide two integers without using multiplication, division and mod operator.
*Return the floor of the result of the division.
*/

int Solution::divide(int dividend, int divisor) {
    long long unsdivd=dividend,unsdivs=divisor;
    int i;
    bool negative=0;
    if(dividend < 0){
        unsdivd=0-unsdivd;
        negative=negative ^ 1;
    }
    if(divisor < 0){
        unsdivs=0-unsdivs;
        negative= negative ^ 1;
    }

    if(unsdivs > unsdivd)
        return 0;
		if(dividend == INT_MIN && divisor==1){
			return INT_MIN;
		}
    long long A=0,M=unsdivs,Q=unsdivd,bit=1,lsb=1;
    i=0;
    while(i<31){
        bit=bit<<1;
        i++;
    }
    int count=32;
    bool msb=0;
    while(count>0){
        A=A<<1;
        msb=Q&bit;
        if(msb) A=A+1;
        Q=Q<<1;
        A=A-M;
        if(A<0){
            A=A+M;
            if(Q&lsb)
                Q=Q-1;
        }else {
            if(!(Q&lsb))
                Q=Q+1;
        }
        count--;
    }
    i=0;
    long long ans=0;
    bit=INT_MAX;
    ans=Q & bit;
    if(negative){
			    ans=0-ans;
		}

   if(ans<INT_MIN || ans >INT_MAX || ans==0)
    return INT_MAX;
    return (int)ans;



    
}
