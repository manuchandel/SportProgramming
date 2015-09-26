int Solution::numDecodings(string A) {
    int q,p,ans;
    int i,n=A.length();

    if(n==1){
        if(A[i]-'0'<=9 && A[i]-'0'>0)
            return 1;
        return 0;
    }
    if(A[0]-'0'>0 &&A[0]-'0'<=9)
        q=1;
    else return 0;
    if(A[0]=='1'){
        if(A[1]-'0'>0 && A[1]-'0'<=9)
            p=2;
        else p=1;
    }
    else if(A[0]=='2'){
        if(A[1]-'0'>0 && A[1]-'0'<=6)
            p=2;
        else p=1;
    }else p=1;
    
    if(n==2)
        return p;
    i=2;
    while(i<n){
        if(A[i]=='0'){
            if(A[i-1]=='1' || A[i-1]=='2'){
                ans=q;
                p=ans;
            }else return 0;
        }else if(A[i]-'0'>=1 && A[i]-'0'<=9){
            if(A[i-1]=='1' ||(A[i-1]=='2' && A[i]-'0'<=6) )
                ans=p+q;
            else ans=p;
            q=p;
            p=ans;
        }
        i++;
    }
    return ans;
}
