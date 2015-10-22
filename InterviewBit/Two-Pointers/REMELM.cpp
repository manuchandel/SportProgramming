/*
 *Given an array and a value, remove all the instances of that value in the array. 
 *Also return the number of elements left in the array after the operation.
 *It does not matter what is left beyond the expected length.
 * If array A is [4, 1, 1, 2, 1, 3]
 *and value elem is 1, 
 *then new length is 3, and A is now [4, 2, 3]
 */
 int Solution::removeElement(vector<int> &A, int B) {
   int n=A.size();
   int i;
    i=0;
   while(i<n && A[i]!=B) i++;
   if(i==n)
        return n;
    int p=i+1;
    while(p<n){
        if(A[p]!=B){ 
        A[i]=A[p];
        i++;
        }
        p++;
    }
    for(;i<n;i++)
        A.pop_back();
    return A.size();
}
