/* Given a set of distinct integers, S, return all possible subsets. */
void subsetcombine(vector< vector<int> > &ans,vector<int> &A, int i){
    int n=A.size();
    if(i==n)
        return;
    vector<int> row;
    subsetcombine(ans,A,i+1);
    int m=ans.size();
    for(int j=0;j<m;j++){
        row.clear();
        row.push_back(A[i]);
        for(int k=0;k< ans[j].size();k++)
            row.push_back(ans[j][k]);
        ans.push_back(row);
    }
    row.clear();
    row.push_back(A[i]);
    ans.push_back(row);
}
vector<vector <int> > Solution::subsets(vector<int> &A) {
   vector< vector<int> > matrix;
   sort(A.begin(),A.end());
   subsetcombine(matrix,A,0);
	 vector<vector<int> > ans;
	 vector<int> row;
	 ans.push_back(row);
	 while(!matrix.empty()){
		 ans.push_back(matrix[matrix.size()-1]);
		 matrix.pop_back();
	 }
	return ans;
}
