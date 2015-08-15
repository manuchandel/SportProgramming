/* Given a collection of numbers, return all possible permutations.*/
void swap(int &a,int &b){
    int c=a;
    a=b;
    b=c;
}
void permutations(vector<int> &A,vector< vector<int> > &v,int l){
  if(l==A.size()-1){
    v.push_back(A);
    return;
  }
  for(int i=l;i<A.size();i++){
    swap(A[l],A[i]);
    permutations(A,v,l+1);
    swap(A[l],A[i]);
  }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > v;
    permutations(A,v,0);
    sort(v.begin(),v.end());
    return v;
}
