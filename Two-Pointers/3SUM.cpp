/* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. 
*/
int closest(vector<int> &A,int start,int end,int B){
    int diff=INT_MAX;
    int sum;
    int ans;
    int p=start,q=end;
    while(q>p){
      sum=A[p]+A[q];
      if(abs(B-sum)<diff){
          diff=abs(B-sum);
          ans=sum;
      }
      if(sum>B)q--;
      else p++;
    }
    return ans;
}
int Solution::threeSumClosest(vector<int> &A, int B) {
    int n=A.size();
    sort(A.begin(),A.end());
    int value;
    int ans=0;
    int diff=INT_MAX;
    for(int i=0;i<n-2;i++){
      value=closest(A,i+1,n-1,B-A[i]);
      value+=A[i];
      if(diff>abs(value-B)){
        ans=value;
        diff=abs(value-B);
      }
    }
    return ans;
}
