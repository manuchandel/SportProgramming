/*
 *Given a list of non negative integers, arrange them such that they form the largest number.
 *Given [3, 30, 34, 5, 9] the largest formed number is 9534330.
 *Time O(nlogn) & space O(1)
 */

/*
 *Given two numbers X and Y, how should myCompare() decide which number to put first – 
 *we compare two numbers XY (Y appended at the end of X) and YX (X appended at the end of Y).
 *If XY is larger, then, in the output, X should come before Y, else Y should come before X
 *For example, let X and Y be 542 and 60. To compare X and Y, we compare 54260 and 60542. Since 60542 is greater than 54260, we put Y first.
 */

 /*
  *g++ -std=c++11 filename
  */
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>
#define FOR(i,n) for(i=0;i<n;i++)
#define IN(x) cin>>x
#define OUT(x) cout<<x
using namespace std;
/* is s1 smaller than s2 */
bool compare(string s1,string s2){
	string s3=s1+s2;
	string s4=s2+s1;
	if(s3>s4)
		return false;
	return true;
}
string Number(int *A,int n){
	int i;	//loop variable
	vector<string> B;
	for(i=0;i<n;i++)
		B.push_back(to_string(A[i]));
	sort(B.begin(),B.begin()+n,compare);	//sort in ascending order
	string s=B[n-1];
	for(i=n-2;i>=0;i--)
		s+=B[i];
	return s;

}
int main(){
	int n;	//no of elements
	IN(n);	//input n
	int i;
	int *arr=new int[n];
	FOR(i,n)
		IN(arr[i]);
	OUT(Number(arr,n));OUT(endl);
	
}
