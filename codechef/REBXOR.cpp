#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
#include <algorithm>
#define MAX 400000
#define ll long long
#define FOR(i,a,n) for(i=a;i<n;i++)
using namespace std;
int TMAX;
int *A=new int[MAX];
int *B=new int[MAX];
int *C=new int[MAX];
struct TrieNode{
    TrieNode *left;
    TrieNode *right;
    TrieNode(): left(0),right(0){}
};
TrieNode *head=0;
TrieNode *trie=new TrieNode[1000000];
int index=0;
TrieNode* createStruct(){
  TrieNode *current=0;
  if(index<1000000){
    current=&trie[index];
    index++;
  }
  else{
    current=new TrieNode();
  }
  return current;
}
void deleteTree(TrieNode* current){
  if(!current)
    return;
  deleteTree(current->left);
  deleteTree(current->right);
  delete current;
}
void add(int n){
  int bit=TMAX;
  TrieNode *current=head;
  while(bit>0){
    if(bit&n){
      if(!(current->right))
        current->right=createStruct();
      current=current->right;
    }else{
      if(!(current->left))
        current->left=createStruct();
      current=current->left;
    }
    bit=bit>>1;
  }
}
int query(int n){
  int bit=TMAX;
  int ans=0;
  TrieNode *current=head;
  while(bit>0 && current){
    if(n&bit){
      if(current->left)
        current=current->left;
      else if(current->right){
        current=current->right;
        ans+=bit;
      }else current=0;
    }else{
      if(current->right){
        current=current->right;
        ans+=bit;
      }else if(current->left)
        current=current->left;
      else current=0;
    }
    bit=bit>>1;
  }
  return ans;
}
 
int foo(int n){
  int temp=0;
  int i;
  head=createStruct();
  add(0);
  FOR(i,0,n){
    temp=temp^A[i];
    B[i]=temp^query(temp);
    add(temp);
  }
  FOR(i,0,1000000)
    trie[i].left=trie[i].right=NULL;
  index=0;
  head=createStruct();
  add(0);
  temp=0;
  for(i=n-1;i>=0;i--){
    temp=temp^A[i];
    C[i]=temp^query(temp);
    add(temp);
  }
  temp=B[0];
  FOR(i,1,n){
    if(temp<B[i])
      temp=B[i];
    else B[i]=temp;
  }
  temp=C[n-1];
  for(i=n-2;i>=0;i--){
    if(temp<C[i])
      temp=C[i];
    else C[i]=temp;
  }
  temp=0;
  FOR(i,0,n-1)
    temp=max(temp,B[i]+C[i+1]);
  return temp;
}
int main(){
  int N,i;
  scanf("%d",&N);
  int temp=0;
  FOR(i,0,N){
    scanf("%d",&A[i]);
    temp=max(temp,A[i]);
  }
  TMAX=1;
  while(temp>0){
    temp=temp>>1;
    TMAX=TMAX<<1;
  }
  printf("%d\n",foo(N));
}
