long long fact[256];
struct s{
    char a;
    bool seen;
};
int get(s array[],char a,int n){
    int x=0;
    for (int i=0;i<n;i++){
        if (!array[i].seen and a>array[i].a){
            x++;
        }
        if (array[i].a==a)
            array[i].seen=true;
    }
    
    return x;
}
int answer(string A){
    
    
    long long ans=0;
    long long mod=1000003;
    s array[A.length()];
    for (int i=0;i<A.length();i++){
       array[i].a=A[i];
       array[i].seen=false;
      }
    
    for(int i=0;i<A.length();i++){
        ans=ans+fact[A.length()-i-1]*get(array,A[i],A.length());
        
        ans%=mod;
    }
    ans+=1;
    ans%=mod;
    return (int)ans;
}
int Solution::findRank(string A) {
    fact[0]=1;
    long long mod=1000003;
    for (int i=1;i<256;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
    }
    
    return answer(A);
}
