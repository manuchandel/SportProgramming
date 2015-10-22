/*
 *There are two sorted arrays A and B of size m and n respectively.
 *Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).
 *The overall run time complexity should be O(log (m+n))
 */


double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
   int l,r,mid;
   int n=A.size();
   int m=B.size();
   if(n==0){
        if(m&1)
            return (double)B[m/2];
        return (double)(B[m/2-1]+B[m/2])/2; 
   }
   if(m==0){
       if(n&1)
            return (double)A[n/2];
        return (double)(A[n/2-1]+A[n/2])/2; 
   }
   int medianIndex;
   int median=-1;
   int medianValue;
   bool first=1;
    l=0; r=n-1;
    while(l<=r){
        mid=(l+r)>>1;
        medianIndex=(n+m)/2-mid;
        if(medianIndex>=0 && medianIndex<m){
           if(A[mid]<=B[medianIndex]){
               if(medianIndex==0 || (medianIndex>0 && B[medianIndex-1]<=A[mid])){
                    median=mid;
                    medianValue=A[mid];
                    l=n;
               }
               else l=mid+1;
           }else r=mid-1;
        }
        else if(medianIndex==m){
            if(A[mid]>=B[medianIndex-1]){
                median=mid;
                medianValue=A[mid];
                l=n;
            }else l=mid+1;
        }
        else if(medianIndex<0) r=mid-1;
        else l=mid+1;
    }
    if(median < 0){
        first=0;
        l=0;r=m-1;
        while(l<=r){
            mid=(l+r)>>1;
            medianIndex=(n+m)/2-mid;
            if(medianIndex>=0 && medianIndex<n){
               if(B[mid]<=A[medianIndex]){
                   if(medianIndex==0 || (medianIndex>0 && A[medianIndex-1]<=B[mid])){
                        median=mid;
                        medianValue=B[mid];
                        l=m;
                   }
                   else l=mid+1;
               }else r=mid-1;
            }
            else if(medianIndex==n){
                if(B[mid]>=A[medianIndex-1]){
                    median=mid;
                    medianValue=B[mid];
                    l=m;
                }else l=mid+1;
        }
            else if(medianIndex<0) r=mid-1;
            else l=mid+1;
        }
    }
    if((m+n)&1)
        return (double)medianValue;
    int value1,value2;
    if(first){
        if(median==0)
            value1=INT_MIN;
        else value1=A[median-1];
         if(B[0]>medianValue)
            return (double)(medianValue+value1)/2;
        l=0;r=m-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(B[mid]==medianValue){
                r=mid;
                l=m;
            }else if(B[mid]<medianValue)
                l=mid+1;
            else r=mid-1;
        }
        value2=B[r];
    }else{
        if(median==0)
            value1=INT_MIN;
        else value1=B[median-1];
        if(A[0]>medianValue)
            return (double)(medianValue+value1)/2;
        l=0;r=n-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(A[mid]==medianValue){
                r=mid;
                l=n;
            }else if(A[mid]<medianValue)
                l=mid+1;
            else r=mid-1;
        }
        value2=A[r];
    }
    return (double)(medianValue+max(value1,value2))/2;
    
}
