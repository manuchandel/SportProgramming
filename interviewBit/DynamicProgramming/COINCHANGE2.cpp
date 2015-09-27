#define mod 1000007
int Solution::coinchange2(vector<int> &A, int B) {
    int table[B+1],n=A.size();
    memset(table,0,sizeof(table));
    table[0]=1;
    int i,j;
    for(i=0;i<n;i++){
        for(j=A[i];j<=B;j++){
            table[j]+=table[j-A[i]];
            table[j]%=mod;
        }
    }
    return table[B];
}
