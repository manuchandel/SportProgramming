vector<int> Solution::repeatedNumber(const vector<int> &A) {
     // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   vector<int> v(2,0);
    int n=A.size();
    long long sum=0,sqsum=0;
    int i;
    for(i=0;i<n;i++){
    	sum+=A[i];
    	sum-=(i+1);
    	sqsum=sqsum+(long long)A[i]*A[i];
    	sqsum=sqsum-(long long)(i+1)*(i+1);
    }
    sqsum/=sum;
    v[0]=(int)(sqsum+sum)>>1;
    v[1]=(int)(sqsum-v[0]);
    return v;
   
}
