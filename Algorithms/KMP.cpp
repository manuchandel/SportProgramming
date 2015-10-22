/*
 *Implement KMP algorithm for pattern matching
 *Time O(length Of Text) space O(length of Pattern)
 */
#include <iostream>
#include <vector>
#define FOR(a,b) for(int a=0;a<b;a++)
using namespace std;
/* This method constructs the longest-prefix-suffix array for the KMP algorithm */
void longestPrefixSuffix(string &p,int *A,int n){
  A[0]=0;
  int i=1,j=0;
  while(i<n){
    if(p[i]==p[j]){ //match found
      A[i]=j+1;
      i++;
      j++;
    }else if(j==0){
      A[i]=0;
      i++;
    }else j=A[j-1]; //search in the next longest prefix
  }
}
/* This method returns the vector whichh have index where the pattern matches in the text else returns empty vector */
vector<int> KMP(string T,string p){
  int n=p.length();
  int N=T.length();
  int *A=new int[n];
  longestPrefixSuffix(p,A,n); //compute lps array
  vector<int> v;  //will store all indices where pattern occurs
  int i=0,j=0;
  while(i<N){
    if(j==n){   //pattern found
      v.push_back(i-n);
      j=A[j-1];
    }
    if(T[i]==p[j]){
      i++;
      j++;
    }else if(j==0) i++;
    else j=A[j-1];
  }
  delete []A; //free memory allocated to array to avoid memory leak
  if(j==n)
    v.push_back(i-n);
  return v;
}
int main()
{
  string T,p;
  cin>>T>>p;
  vector<int> v=KMP(T,p);
  FOR(i,v.size())
    cout<<v[i]<<" ";
  cout<<endl;
}
