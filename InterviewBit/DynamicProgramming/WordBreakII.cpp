void generateString(vector<vector<int>> &v,string A,string B, vector<string> &vs,int i){
    int n=A.length();
    if(i==n){
        string C=B.substr(0,B.length()-1);
        vs.push_back(C);
        return;
    }
    for(int j=i;j<n;j++)
        if(v[i][j]==1)
            generateString(v,A,B+A.substr(i,j-i+1)+" ",vs,j+1);
    
}
vector<string> Solution::wordBreak(string A, vector<string> &B) {
    int i,j;
    int n=A.length();
    vector<vector<int>> v;
    vector<int> v1(n+1,0);
    v1[n]=1;
    for(i=0;i<n;i++){
        vector<int> r(n,0);
        v.push_back(r);
    }
    unordered_map<string,int> dict;
    for(i=0;i<B.size();i++)
        dict[B[i]]=1;
    if(dict.find(A.substr(n-1,1))!=dict.end()){
        v[n-1][n-1]=1;
        v1[n-1]=1;
    }
    for(i=n-2;i>=0;i--){
        for(j=i;j<n;j++){
            string s=A.substr(i,j-i+1);
            if(dict.find(s)!=dict.end() && v1[j+1]==1){
                v[i][j]=1;
                v1[i]=1;
            }
        }
    }
    vector<string> vs;
    generateString(v,A,"",vs,0);
    sort(vs.begin(),vs.end());
    dict.clear();
    return vs;
        
    
}
