/*
 *Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 */
int Solution::trap(const vector<int> &A) {
    stack<int> mystack;
    int temp=0;
    int ans=0;
    int i=1,j=0;
    mystack.push(A[0]);
    for(i=0;i<A.size();i++){
        if(A[i]>A[j])
            j=i;
    }
    i=0;
    while(i<=j){
        if(A[i]>=mystack.top()){
            ans+=temp;
            temp=0;
            mystack.pop();
            mystack.push(A[i]);
        }else temp+=mystack.top()-A[i];
        i++;
    }
    while(!mystack.empty()) mystack.pop();
    mystack.push(A[A.size()-1]);
    i=A.size()-2;
    temp=0;
     while(i>=j){
        if(A[i]>=mystack.top()){
            ans+=temp;
            temp=0;
            mystack.pop();
            mystack.push(A[i]);
        }else temp+=mystack.top()-A[i];
        i--;
    }
    return ans;
}
