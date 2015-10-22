/*
 *Place n queens on a nxn chess board such that no queen attacks any other queen
 */
#include <iostream>
using namespace std;
void print(bool **a,int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      cout<<a[i][j]<<" ";
    cout<<endl;
  }
}
/* function that determines whether the position i,j is safe for queen or not */
bool isSafe(bool **a,int i,int j,int n){
  for(int k=i-1;k>=0;k--)
    if(a[k][j])
      return 0;
  int p=i-1,q=j-1;
  while(p>=0 && q>=0){
    if(a[p][q])
      return 0;
    p--;q--;
  }
  p=i-1;q=j+1;
  while(p>=0 && q<n){
    if(a[p][q])
      return 0;
    p--;q++;
  }
  return 1;
}
/* function which places queens on chessboard */
bool placeQueens(bool **a,int i,int n){
  if(i==n)
    return 1;
  int j;
  for(j=0;j<n;j++){
    /*print(a,n);
    cout<<endl<<endl;*/
    if(isSafe(a,i,j,n)){
        a[i][j]=1;
        if(!placeQueens(a,i+1,n))
          a[i][j]=0;
        else return true;
    }
  }
  return false;
}

int main()
{
  int n;
	cin>>n;
	bool **a=new bool *[n];
	for(int i=0;i<n;i++)
		a[i]=new bool[n];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      a[i][j]=0;
	placeQueens(a,0,n);
  print(a,n);
}
