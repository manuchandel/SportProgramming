/*Given an index k, return the kth row of the Pascal’s triangle.

 *Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
 */


vector<int> Solution::getRow(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector <int> v(A+1,0);
    v[0]=1;
    int pre1,previous;
    for(int i=1;i<A+1;i++){
    	previous=1;
    	for(int j=1;j<i;j++){
    		pre1=v[j];
    		v[j]=v[j]+previous;
    		previous=pre1;
    	}
    	v[i]=1;
    }
    return v;
}
