/*
 *Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.
 *For simplicity, assume that all bars have same width and the width is 1 unit.
 *Time =O(n) & Space =O(n)
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#define IN(a) cin>>a
#define OUT(a) cout<<a
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
/* Returns max rect area in a histogram */
int maxArea(vector<int> &A) {
  stack<int>mystack;
  int l=-1,r=0;
  int n=A.size();
  int maxA=0;
  int i=0,temp;
  while(i<n){
      if(mystack.empty()||A[mystack.top()]<=A[i])
        mystack.push(i);
      else if(A[mystack.top()]>A[i]){
        r=i;
        while(!mystack.empty()&& A[mystack.top()]>A[i]){
            temp=mystack.top();
            mystack.pop();
            if(!mystack.empty())
                l=mystack.top();
            else l=-1;
            maxA=max(maxA,A[temp]*(r-l-1));
        }
        mystack.push(i);
        }
        i++;
  }
  r=n;
  while(!mystack.empty()){
                temp=mystack.top();
                mystack.pop();
                if(!mystack.empty())
                    l=mystack.top();
                else l=-1;
                maxA=max(maxA,A[temp]*(r-l-1));
            }
    return maxA;
}

int main(){
  int n;
  int b;
  IN(n);
  vector<int> A;
  for(int i=0;i<n;i++){
    IN(b);
    A.push_back(b);
  }
  OUT(maxArea(A)<<endl);
}
