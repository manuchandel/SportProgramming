/* Multiply Two Strings */

string add(string A,string B){
    int n= A.length();
    int m=B.length();
    int i=0;
    int sum=0,carry=0;
    while(i<m){
        sum=A[i]-'0'+B[i]-'0'+carry;
        carry=sum/10;
        sum=sum%10;
        A[i]=sum+'0';
        i++;
    }
    while(i<n){
        sum=A[i]-'0'+carry;
        carry=sum/10;
        sum=sum%10;
        A[i]=sum+'0';
        i++;
    }
    if(carry > 0)
        A+=carry+'0';
    return A;
}
string funct(string A, string B){
    string c;
    string d="";
    int i,j,k;
    int quot,remain;
    int a,b;
    for(i=0;i<A.length();i++)
        d+='0';
    for(i=B.length()-1;i>=0;i--){
        remain=0;
        quot=0;
        b=B[i]-'0';
        c="";
        for(k=i;k<B.length()-1;k++)
            c+='0';
        for(j=A.length()-1;j>=0;j--){
            a=A[j]-'0';
            quot=a*b+quot;
            remain=quot%10;
            c+=remain+'0';
            quot/=10;
        }
        if(quot > 0)
            c+=quot+'0';
        d=add(c,d);
    }
    char temp;
    int n=d.length();
    for(i=0;i<n/2;i++){
        temp=d[i];
        d[i]=d[n-1-i];
        d[n-1-i]=temp;
    }
    return d;
}
string Solution::multiply(string A, string B) {
    string bigger="";
    string smaller="";
    int i=0,j=0;
    while(i<A.length() && A[i]=='0')i++;
    if(i==A.length()){
        bigger="0";
        return bigger;
    }
    while(j<B.length() && B[j]=='0')j++;
    if(j==B.length()){
        bigger="0";
        return bigger;
    }
    if(A.length()-i >= B.length()-j){
        for(;i<A.length();i++)
            bigger+=A[i];
        for(;j<B.length();j++)
            smaller+=B[j];
    }else{
        for(;i<A.length();i++)
            smaller+=A[i];
        for(;j<B.length();j++)
            bigger+=B[j];
    }
    return funct(bigger,smaller);
}
