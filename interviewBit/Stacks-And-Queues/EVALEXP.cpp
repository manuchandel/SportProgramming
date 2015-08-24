/* evaluate rpn */
int evalRPN(vector<string> &A) {
   stack<int> mystack;
   int n=A.size();
   int a=0,b=0;
   for(int i=0;i<n;i++){
       if(A[i][0]=='-' && A[i].length()>1){
           a=stoi(A[i],nullptr,10);
           mystack.push(a);
           
       }
       else if(A[i][0]-'0'<=9 &&A[i][0]-'0'>=0)
            mystack.push(stoi(A[i],nullptr,10));
        else{
            a=mystack.top();
            mystack.pop();
            b=mystack.top();
            mystack.pop();
            if(A[i]=="/"){
                if(a==0)
                    return 0;
               b=b/a;
            }
            else if(A[i]=="*")
                b=b*a;
            else if(A[i]=="+")
                b=b+a;
            else b=b-a;
            mystack.push(b);
        }
   }
   b=mystack.top();
   mystack.pop();
   return b;
   
   
}
