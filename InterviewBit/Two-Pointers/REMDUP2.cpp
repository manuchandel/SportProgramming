/* Given a sorted array,remove the duplicates in place such that 
 *each element appear atmost twice and return the new length.
 */
int Solution::removeDuplicates(vector<int> &A) {
   int n=A.size();
   if(n==0)
    return 0;
   int m=A[n-1];
   int i;
   int freq=1;
   int p=0;
   for(i=1;i<n;i++){
       if(A[i]==A[p])
        freq++;
        else
        {
            freq=1;
            p=i;
        }
        if(freq>=3)
            A[i]=m+1;
   }
   i=0;
   while(i<n && A[i]!=(m+1))i++;
   if(i==n)
    return n;
    p=i+1;
    while(p<n){
        if(A[p]!=(m+1)){
        A[i]=A[p];
        i++;
        }
        p++;
    }
    for(;i<n;i++)
        A.pop_back();
    return A.size();
}
