/*
 *write program to validate if the input string has redundant braces ?
 *Return 0 if not redundant else 1
 */

int Solution::braces(string A) {
    stack<char> mystack;
    int i;
    int n=A.length();
    bool redundant=0;
    bool express;
    for(i=0;i<n && !redundant ;i++){
        if(A[i]=='('|| A[i]=='+' || A[i]=='-' || A[i]=='/' || A[i]=='*')
            mystack.push(A[i]);
        else if(A[i]==')'){
            express=0;
            while(mystack.top()!='('){
                if(mystack.top()== '*' || mystack.top()== '+' 
                || mystack.top()=='-' || mystack.top()=='/'){
                    express=1;
                }
                mystack.pop();
            }
            mystack.pop();
            if(!express)
                redundant=1;
        }
    }
    if(redundant)
        return 1;
    return 0;
}
