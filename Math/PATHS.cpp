/*
 *The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).
 *How many possible unique paths are there?
 *Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.
 */

int gcd(int A, int B) {
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
    int array1[30];
    int array2[30];
    int i,j,n=smaller;
    int cf=1;
    for(i=0;i<n;i++){
        array1[i]=bigger+smaller-i;
        array2[i]=(1+i);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          cf=gcd(array1[i],array2[j]);
          array1[i]/=cf;
          array2[j]/=cf;
        }
    }
    bigger=1;
    for(i=0;i<n;i++)
        bigger=bigger*array1[i];
    return bigger;
    
}
