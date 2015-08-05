/* Find the intersection of two sorted arrays. */
vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
   int p=0,q=0;
   int n=A.size(),m=B.size();
   vector<int> ans;
   while(p<n && q<m){
       if(A[p]==B[q]){
            ans.push_back(A[p]);
            p++;
            q++;
       }
       else if(A[p]>B[q])   q++;
       else p++;
   }
   return ans;
}
