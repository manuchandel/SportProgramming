/* Given an array of 0 1 and 2 sort it */
void swap(int &a,int &b){
    int c=a;
    a=b;
    b=c;
}
int twopointers(vector<int> &A,int b,int n){
    int p=0,q=n-1;
    while(p<q){
       if(A[q]==b)
        q--;
        else if(A[p]==b){
            swap(A[p],A[q]);
            p++;
            q--;
        }else p++;
    }
    for(p=0;p<n;p++)
        if(A[p]==b)
            return p;
    return n;
}
void Solution :: sortColors(vector<int> &A) {
   int n=A.size();
   int one=twopointers(A,2,n);
   twopointers(A,1,one);
}
