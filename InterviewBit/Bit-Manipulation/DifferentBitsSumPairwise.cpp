#define mod 1000000007
int Solution::cntBits(vector<int> &A) {
    long long even,odd;
    long long ans=0;
    int n=A.size();
    int i,j,allzero=0;
    while(allzero<n){
        even=0;odd=0;
        allzero=0;
        for(j=0;j<n;j++){
            if(A[j]&1)
                odd++;
            else even++;
            if(A[j]==0)
                allzero+=1;
            A[j]=A[j]>>1;
        }
        ans+=(odd*even);
        ans%=mod;
    }
    ans%=mod;
    ans=(ans<<1);
    ans%=mod;
    return (int)ans;
}
