/*
 *Given a set of candidate numbers (C) and a target number (T),
 *find all unique combinations in C where the candidate numbers sums to T.
 */
void generateCombinations(vector< vector<int> > &v,vector<int> &row,vector<int> &A,int B,int i){
        if(B==0){
            v.push_back(row);
            return;
        }
        if(i==A.size() || B<0)
            return;
        row.push_back(A[i]);
        generateCombinations(v,row,A,B-A[i],i);
        row.pop_back();
        generateCombinations(v,row,A,B,i+1);
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector< vector<int> > v;
    vector<int> row;
    vector<int> b;
    sort(A.begin(),A.end());
    b.push_back(A[0]);
    for(int i=1;i<A.size();i++){
      if(A[i]!=b[b.size()-1])
        b.push_back(A[i]);
    }
    generateCombinations(v,row,b,B,0);
    return v;
}
