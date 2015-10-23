#define mod 10000003
#define ll long long
ll  hops(string A,int si){
    int i,k=si,n=A.length();
    ll count=0;
    for(i=0;i<n;i++){
        if(A[i]=='x'){
           count+=(ll)abs(i-k);
           k++;
        }
    }
    //printf("%d %lld\n",si,count);
    return count;
}
int Solution::seats(string A) {
    int i,n=A.length(),x=0,l=0,med;
    ll count=INT_MAX;
    for(i=0;i<n;i++){
        if(A[i]=='x')
            x++;
    }
    for(i=0;i<n;i++){
        if(A[i]=='x'){
            l++;
            if(l==(x/2)+1){
                med=i;
                break;
            }
        }
    }
    if(x==0)
        return 0;
    string B=A.substr(med,n-med);
    string C=A.substr(0,med);
    for(i=0;i<med/2;i++)
        swap(C[i],C[med-1-i]);
    //cout<<B<<" "<<C<<endl;
    count=hops(B,0);
    count%=mod;
    count+=hops(C,0);
    count%=mod;
    return (int)count;  
}
