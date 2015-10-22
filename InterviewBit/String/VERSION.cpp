/* Compare two version numbers version1 and version2. */
string trim(string A){
    int m=A.length();
    string temp="";
    int i=0;
    while(i<m && A[i]=='0') i++;
    if(i==m)
        temp="0";
    else {
        for(;i<m;i++)
            temp+=A[i];
    }
    return temp;
}
string number(string A,int &i){
    string temp="";
    while(i<A.length() && A[i]!='.'){
        temp+=A[i];
        i++;
    }
    return trim(temp);
}
int Solution::compareVersion(string A, string B) {
    int i=0;
    int j=0;
    string number1="1",number2="1";
    while(i<A.length() || j<B.length()){
        number1=number(A,i);
        i++;
        number2=number(B,j);
        j++;
        if(number1.length()==number2.length()){
            if(number1>number2)
                return 1;
            else if(number1<number2)
                return -1;
        }else{
            if(number1.length()>number2.length())
                return 1;
            else return -1;
        }
    }
    return 0;
    
    
}
