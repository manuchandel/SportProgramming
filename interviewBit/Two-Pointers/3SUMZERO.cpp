/*
 *Given an array S of n integers, are there elements a, b, c in S such that
 *a + b + c = 0 ? 
 *Find all unique triplets in the array which gives the sum of zero.
 */
vector<vector<int> > Solution::threeSum(vector<int> &A) {
  int n=A.size();
  vector<int> v(3,0);
  vector< vector<int> > B;
  sort(A.begin(),A.end());
  int i,j;
  int p,q,r;
  for(i=2;i<n;i++){
      p=0;q=i-1;r=-1*A[i];
      if(i==n-1 || A[i]!=A[i+1]){
        while(p<q){
            if(r==A[p]+A[q]){
                v[0]=A[p];
                v[1]=A[q];
                v[2]=A[i];
                if(B.size()>0 && B[B.size()-1][0]==v[0]&&B[B.size()-1][1]==v[1]&&
                B[B.size()-1][2]==v[2]);
               else B.push_back(v);
              p++;
              q--;
            }else if(r>A[p]+A[q]) p++;
            else q--;
        }
      }
  }
  return B;
}
