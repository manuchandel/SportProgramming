int Solution::majorityElement(const vector<int> &A) {
    //moores voting algorithm
    int i,n=A.size();
    int candidate;
    int count=0;
    for(i=0;i<n;i++){
        if(count==0){
            candidate=A[i];
            count++;
        }
        else if(A[i]==candidate)
            count++;
        else if(A[i]!=candidate)
            count--;
    }
    return candidate;
}

