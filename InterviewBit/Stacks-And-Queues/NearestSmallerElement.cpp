vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> mystack;
    int n=A.size();
    vector<int> v;
    mystack.push(-1);
    for(int i=0;i<n;i++){
        if(A[i]>mystack.top()){
            v.push_back(mystack.top());
            mystack.push(A[i]);
        }else{
            while(A[i]<=mystack.top()) mystack.pop();
            v.push_back(mystack.top());
            mystack.push(A[i]);
        }
    }
    return v;
}
