
/* find gcd of two numbers */
int Solution::gcd(int A, int B) {
    if(A==0)
        return B;
    else if(B==0)
        return A;
   int y=1;
	while(y>0){
		y=A%B;
		A=B;
		B=y;
	}
	return A;
}
