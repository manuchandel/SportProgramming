/*
 *Find if Given number is power of 2 or not. 
 *More specifically, find if given number can be expressed as 2^k where k >= 1.
 */
string multiplyby2(string A){
    string ans="";
    int i;
    int n=A.length();
    int sum=0,carry=0;
    for(i=n-1;i>=0;i--){
        sum=(A[i]-'0')*2+carry;
        carry=sum/10;
        sum%=10;
        ans+=(sum+'0');
    }
    if(carry>0)
        ans+=(carry+'0');
    n=ans.length();
    char c;
    for(i=0;i<n/2;i++){
        c=ans[i];
        ans[i]=ans[n-1-i];
        ans[n-1-i]=c;
    }
    return ans;
}
bool compare(string A,string B){
    if(A.length()==B.length())
        return A<B;
    else if(A.length()<B.length())
        return true;
    return false;
}
int Solution::power(string A) {
    int i=0;
    int n=A.length();
    string B="";
    while(i<n && A[i]=='0') i++;
    if(i==n)
        return 0;
    while(i<n){
        B+=A[i];
        i++;
    }
    string temp="2";
    while(compare(temp,B)){
        temp=multiplyby2(temp);
    }
    if(temp.length()==B.length() && temp==B)
        return 1;
    return 0;
    
}
