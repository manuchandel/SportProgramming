/*
 *Given an array, print the Next Greater Element (NGE) for every element.
 *The Next greater Element for an element x is the first greater element on the right side of x in array.
 *Elements for which no greater element exist, consider next greater element as -1.
 *Time=O(n) & space O(n)
 */
#include <cstdio>
#include <stack>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
#define OUT(a) printf("%d ",a)
#define LN printf("\n")
using namespace std;
stack <int> mystack;
void nextGreaterElement(int *array,int n){
	int i=0;	//loop variable
	int temp;	//temporary variable
	while(i<n){
		if(mystack.empty()){
			mystack.push(array[i]);
			i++;
		}else{
			temp=mystack.top();
			if(temp<array[i]){
				mystack.pop();
				OUT(temp);OUT(array[i]);LN;
			}else{
				mystack.push(array[i]);
				i++;
			}
		}
	}
	while(!mystack.empty()){	//rest all elements dont have NGE
		OUT(mystack.top());OUT(-1);LN;
		mystack.pop();
	}
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	IN(n);
	int *array=new int[n];
	FOR(i,n)
		IN(array[i]);
	nextGreaterElement(array,n);

}
