int Solution::bulbs(vector<int> &A) {
    int n=A.size();
    int i=0,j;
    int toggles=0;
    bool toggle=0;
    while(i<n){
        if(toggle)
            A[i]=1-A[i];
        if(A[i]==0){
            A[i]=1;
            if(toggle==0)
                toggle=1;
            else toggle=0;
            toggles++;
        }
        i++;
    }
    return toggles;
}
