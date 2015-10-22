/*Given an integer n, return all distinct solutions to the n-queens puzzle.*/
bool isSafe(vector< vector<string> > a,int i,int j,int n){
  for(int k=i-1;k>=0;k--)
    if(a[k][j]=="Q")
      return 0;
  int p=i-1,q=j-1;
  while(p>=0 && q>=0){
    if(a[p][q]=="Q")
      return 0;
    p--;q--;
  }
  p=i-1;q=j+1;
  while(p>=0 && q<n){
    if(a[p][q]=="Q")
      return 0;
    p--;q++;
  }
  return 1;
}
bool placeQueens(vector< vector<string> > &ans,vector< vector<string> > &a,int i,int n){
  if(i==n){
    vector<string> row;
    ans.push_back(row);
    string temp="";
    int k=ans.size();
    for(int l=0;l<n;l++){
        temp="";
      for(int m=0;m<n;m++){
        temp+=a[l][m];
      }
      ans[k-1].push_back(temp);
    }

    return 0;
  }
  for(int j=0;j<n;j++){
    if(isSafe(a,i,j,n)){
        a[i][j]="Q";
        if(!placeQueens(ans,a,i+1,n))
          a[i][j]=".";
        else return true;
    }
  }
  return false;
}
vector< vector<string> > Solution ::solveNQueens(int A) {
    vector< vector<string> > v;
    vector< vector<string> > ans;
     if(A==3 || A==2)
        return v;
    vector<string> row;
    for(int i=0;i<A;i++)
        row.push_back(".");
    for(int i=0;i<A;i++)
        v.push_back(row);
    placeQueens(ans,v,0,A);
    return ans;

}
