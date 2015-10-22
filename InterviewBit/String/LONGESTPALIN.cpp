/* Given a string S, find the longest palindromic substring in S. */
string Solution::longestPalindrome(string A) {
   int i,j;
    int n=A.length();
    if(n==1)
        return A;
    string B="";
    int p,q,l=0,start,end;
    for(i=0;i<n-1;i++){
        p=q=i;
        while(p>=0 && q<n && A[p]==A[q]){
            if(q-p+1 > l){
                l=q-p+1;
                start=p;
                end=q;
            }
            p--;q++;
        }
        if(B.length()<l){
            B="";
            for(j=start;j<=end;j++)
                B+=A[j];
        }
        if(A[i]==A[i+1]){
            p=i;q=i+1;
            while(p>=0 && q<n && A[p]==A[q]){
                if(q-p+1 > l){
                    l=q-p+1;
                    start=p;
                    end=q;
                }
                p--;q++;
            }
            if(B.length()<l){
                B="";
                for(j=start;j<=end;j++)
                    B+=A[j];
            }
        }
    }
    return B;
}
