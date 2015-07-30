void reverseString(string &A){
    int i=0;
    char c;
    int n=A.length();
    for(i=0;i<n/2;i++){
        c=A[i];
        A[i]=A[n-i-1];
        A[n-i-1]=c;
    }
}
string Solution::addBinary(string A, string B) {
    string c="";
    int n=A.length();
    int m=B.length();
    reverseString(A);
    reverseString(B);
    int i=0;
    int sum=0,carry=0;
    while(i<n && i<m){
        sum=(A[i]-'0')+(B[i]-'0')+carry;
        carry=sum/2;
        sum%=2;
        c+=(sum+'0');
        i++;
    }
    while(i<n){
        sum=(A[i]-'0')+carry;
        carry=sum/2;
        sum%=2;
        c+=(sum+'0');
        i++;
    }
     while(i<m){
        sum=(B[i]-'0')+carry;
        carry=sum/2;
        sum%=2;
        c+=(sum+'0');
        i++;
    }
    if(carry>0)
        c+='1';
    reverseString(c);
    return c;
}
