
/* find gcd of two numbers */
int Solution::gcd(int A, int B) {
    if(A==0)
        return b;
    else if(B==0)
        return a;
   int y=1;
	while(y>0){
		y=A%B;
		A=B;
		b=B=y;
	}
	return A;
}
