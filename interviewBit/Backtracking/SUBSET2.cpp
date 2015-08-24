/* Given a collection of integers that might contain duplicates, S, return all possible subsets. */
void sst(vector< vector<int> > &ans, vector<int> &A,
                            vector<int> &row,int i){
    if(i>=A.size())
        return;

    int lastIndex=i+1;
    while(lastIndex<A.size() && A[i]==A[lastIndex]) lastIndex++;
    for(int m=i;m<lastIndex;m++){
      for(int k=i;k<=m;k++)
        row.push_back(A[i]);
      ans.push_back(row);
      sst(ans,A,row,lastIndex);
      for(int k=i;k<=m;k++)
        row.pop_back();
  }
  sst(ans,A,row,lastIndex);
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
 vector< vector<int> > matrix;
   vector<int> row;
   sort(A.begin(),A.end());
   matrix.push_back(row);
   sst(matrix,A,row,0);
   sort(matrix.begin(),matrix.end());
	return matrix;
}
