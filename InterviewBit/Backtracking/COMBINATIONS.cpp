/*
 *Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.
 *To elaborate,
 *1. Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
 *2. Entries should be sorted within themselves.
 */
void backTrack(vector<vector<int>> &v,vector<int> &row,int i,int n,int k){
    if(k==0){
        v.push_back(row);
        return;
    }
    if(i==n)
        return;
    for(int j=i;j<n;j++){
        row.push_back(j+1);
        backTrack(v,row,j+1,n,k-1);
        row.pop_back();
    }
}
vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int>> v;
    vector<int> row;
    backTrack(v,row,0,n,k);
    return v;
}
