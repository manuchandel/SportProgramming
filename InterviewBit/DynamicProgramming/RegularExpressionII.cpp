bool dp[3000][3000];
bool seen[3000][3000];
bool solve(bool arr[],const string &s,string &p,int i,int j);
bool memoize(bool arr[],const string &s,string &p,int i,int j){
    if(i==s.length() and j==p.length())
        return true;
    
    if(i==s.length() or j==p.length())
        return false;
    if(seen[i][j])
        return dp[i][j];
    
    dp[i][j]=solve(arr,s,p,i,j);
    seen[i][j]=true;
    return dp[i][j];
}

bool solve(bool arr[],const string &s,string &p,int i,int j){
    if(i==s.length() and j==p.length())
        return true;
    
    if(i==s.length() or j==p.length())
        return false;
        
    if(arr[j]){
        if(s[i]==p[j] or p[j]=='.'){
            bool a= memoize(arr,s,p,i+1,j);
            bool b= memoize(arr,s,p,i+1,j+1);
            bool c= memoize(arr,s,p,i,j+1);
            return (a or b or c);
        }else{
            return memoize(arr,s,p,i,j+1);
        }
    }
    else{
        if(p[j]=='.' or s[i]==p[j])
            return memoize(arr,s,p,i+1,j+1);
        return false;
    }
}
int Solution::isMatch(const string &s, const string &p) {
    
    bool arr[p.length()];
    int i,j;
    string regex="";

    
    for(i=0;i<p.length();i++){
        if(p[i]=='*'){
            arr[regex.length()-1]=true;
        }else{
            arr[regex.length()]=false;
            regex+=p[i];
        }
    }
    int n=s.length();
    int m=regex.length();
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            dp[i][j]=false;
            seen[i][j]=false;
        }
    
    return solve(arr,s,regex,0,0);
    
    
    
}
