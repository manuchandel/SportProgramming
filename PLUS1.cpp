/*
 *Given a non-negative number represented as an array of digits,
 *add 1 to the number ( increment the number represented by the digits ).
 *The digits are stored such that the most significant digit is at the head of the list.
 */

void swap(int& a,int &b){
	int c=a;
	a=b;
	b=c;
}
vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i;
    int n=A.size();
    int sum,carry=1;
    for(i=0;i<n/2;i++)  //reverse the vector
   		swap(A[i],A[n-1-i]);
   	i=n-1;
   	while(A[i]==0 && i>=0){ //trim zeros
    	A.pop_back();
    	i--;
    }
    n=A.size();
    for(i=0;i<n;i++){ //perform addition
    	sum=carry+A[i];
    	carry=sum/10;
    	sum=sum%10;
    	A[i]=sum;
    }
    if(carry>0) //add carry bit
    	A.push_back(carry);
    n=A.size();
    for(i=0;i<n/2;i++)  //reverse array
   		swap(A[i],A[n-1-i]);
    return A;
}
