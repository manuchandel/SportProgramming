/*
 *Given a sorted array of integers, find the starting and ending position of a given target value.
 *Your algorithm’s runtime complexity must be in the order of O(log n).
 *If the target is not found in the array, return [-1, -1].
 */
 
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    vector<int> v(2,-1);
    int n=A.size();
    int l=0,r=n-1;
    int mid;
    int li=-1,ri=-1;
   /* finds left index*/
    while(l<=r){
       mid=(l+r)>>1;
       if(A[mid]==B){
           if(mid==0){
            li=mid;
            l=n;
           }else if(A[mid-1]==B){
               r=mid-1;
           }else if(A[mid-1]!=B){
               li=mid;
               l=n;
           }
       }else if(A[mid]>B) r=mid-1;
       else l=mid+1;
    }
    if(li<0)
        return v;
   /* finds right index */
   l=0; r=n-1;
    while(l<=r){
       mid=(l+r)>>1;
       if(A[mid]==B){
           if(mid==n-1){
            ri=mid;
            l=n;
           }else if(A[mid+1]==B){
               l=mid+1;
           }else if(A[mid+1]!=B){
               ri=mid;
               l=n;
           }
       }else if(A[mid]>B) r=mid-1;
       else l=mid+1;
   }
   v[0]=li;
   v[1]=ri;
   return v;
   
}
