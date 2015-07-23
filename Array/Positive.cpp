/*
 *Given an unsorted integer array, find the first missing positive integer
 */
 
 /*
  *turning array into frequency array
  */


int Solution::firstMissingPositive(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   int n=A.size();
    int i=0,index;
    for(i=0;i<n;i++)
    	if(A[i]<0 || A[i]>n)
    		A[i]=0;
    i=0;
    while(i<n){
    	if(A[i]>0){
    		index=A[i]-1;
    		if(A[index]>=0)
				A[i]=A[index];
			else A[i]=0;
			A[index]=-1;
    	}else i++;
    }
    for(i=0;i<n;i++)
    	if(A[i]==0)
    		return (i+1);
    return (i+1);
}
