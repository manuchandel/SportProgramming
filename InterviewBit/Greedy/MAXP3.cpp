int Solution::maxp3(vector<int> &A) {
    int n=A.size();
    int a1=n,a2=n,a3=n;
    int i;
    int threepos=INT_MIN,onepos=INT_MIN;
    A.push_back(INT_MIN);
    //first all three positive
    for(i=0;i<n;i++){
        if(A[i]>=0 && A[i]>A[a1])
            a1=i;
    }
    for(i=0;i<n;i++){
        if(A[i]>=0 && A[i]>A[a2] && i!=a1)
            a2=i;
    }
    for(i=0;i<n;i++){
        if(A[i]>=0 && A[i]>A[a3] && i!=a1 && i!=a2)
            a3=i;
    }
    if(a1!=n && a2!=n && a3!=n)
        threepos=A[a1]*A[a2]*A[a3];
    A[n]=INT_MAX;
    // one pos two neg
    if(a1!=n){
        a2=a3=n;
        for(i=0;i<n;i++){
            if(A[i]<0 && A[i]<A[a2])
                a2=i;
        }
        for(i=0;i<n;i++){
            if(A[i]<0 && A[i]<A[a3] && i!=a2)
                a3=i;
        }
        if(a2!=n && a3!=n){
            onepos=A[a1]*A[a2]*A[a3];
            return max(threepos,onepos);
        }else if(threepos>=0)
            return threepos;
    }
    // minimum of abs val
    a1=a2=a3=n;
    for(i=0;i<n;i++){
        if(abs(A[i])<abs(A[a1]))
            a1=i;
    }
    for(i=0;i<n;i++){
        if(abs(A[i])<abs(A[a2]) && i!=a1)
            a2=i;
    }
    for(i=0;i<n;i++){
        if(abs(A[i])<abs(A[a3]) && i!=a1 && i!=a2)
            a3=i;
    }
    return A[a1]*A[a2]*A[a3];
}
