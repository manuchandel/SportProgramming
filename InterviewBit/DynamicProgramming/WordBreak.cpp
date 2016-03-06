int Solution::wordBreak(string A, vector<string> &B) {
    int i,j;
    int n=A.length();

    vector<int> v(n+1,0);
    v[n]=1;
    unordered_map<string,int> dict;
    for(i=0;i<B.size();i++)
        dict[B[i]]=1;
    if(dict.find(A.substr(n-1,1))!=dict.end())
        v[n-1]=1;
    for(i=n-2;i>=0;i--){
        for(j=i;j<n;j++){
            string s=A.substr(i,j-i+1);
            if(dict.find(s)!=dict.end() && v[j+1]==1){
                v[i]=1;
                break;
            }
        }
    }
    return v[0];
}
