/*
 *Given a collection of candidate numbers (C) and a target number (T),
 *find all unique combinations in C where the candidate numbers sums to T.
 *Each number in C may only be used once in the combination.
 */
void combinations(vector<int> &row,vector<int> &A,vector<vector<int>> &a,
                        int i,int sum,int &val){
    if(sum==val){
        int j;
        int n=0;
        if(a.size()==0 || a[a.size()-1].size()!=row.size())
            a.push_back(row);
        else{
            for(j=0;j<row.size();j++)
                if(row[j]==a[a.size()-1][j])
                    n++;
            if(n!=row.size())
                a.push_back(row);
        }
        
        return;
    }
    if(sum > val || i==A.size())
            return;
    sum+=A[i];
    row.push_back(A[i]);
    combinations(row,A,a,i+1,sum,val);
    sum-=A[i];
    row.pop_back();
    combinations(row,A,a,i+1,sum,val);
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int>> a;
    vector<int> row;
    sort(A.begin(),A.end());
    combinations(row,A,a,0,0,B);
    return a;
}
