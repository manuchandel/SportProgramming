/* Given an absolute path for a file (Unix-style), simplify it. */
string Solution::simplifyPath(string A) {
    stack<string> mystack;
    int n=A.length();
    string temp="";
    bool path=0;
    int i,j;
    for(i=0;i<n;i++){
        if(A[i]=='/'){
            path=1;
            if(temp.length()>2)
                path=0;
            for(j=0;j<temp.length() && path;j++){
                if(temp[j]!='.')
                    path=0;
            }
            if(!path)
                mystack.push(temp);
            else{
                if(temp.length()==2){
                    if(!mystack.empty())
                        mystack.pop();
                }
            }
            temp="";
        }
        else temp+=A[i];
    }
    path=1;
    if(temp.length()>2)
        path=0;
    for(j=0;j<temp.length() && path;j++){
        if(temp[j]!='.')
            path=0;
    }
    if(!path)
        mystack.push(temp);
    else{
        if(temp.length()==2){
            if(!mystack.empty())
                mystack.pop();
        }
    }
    stack<string> ans;
    while(!mystack.empty()){
        ans.push(mystack.top());
        mystack.pop();
    }
    string s="";
    while(!ans.empty()){
        s+="/";
        s+=ans.top();
        ans.pop();
    }
    if(s.length()==0)
        s="/";
    return s;
}
