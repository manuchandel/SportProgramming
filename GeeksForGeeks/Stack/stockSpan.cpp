/*
 *The stock span problem is a financial problem where we have a series of n daily price quotes for a stock.
 *we need to calculate span of stock’s price for all n days. 
 *The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, 
 *for which the price of the stock on the current day is less than or equal to its price on the given day.
 *{100, 80, 60, 70, 60, 75, 85} =>{1, 1, 1, 2, 1, 4, 6} 
 *{10, 4, 5, 90, 120, 80} => {1, 1, 2, 4, 5, 1}
 *Time=O(n)  & Worst space=O(n)
 *
 */
#include <cstdio>
#include <stack>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
void stockspan(int *array,int n){
	int i;	//loop variable
	int temp;
	stack <int> mystack;
	mystack.push(0);
	FOR(i,n){
		while(mystack.size()>1 && array[i]>=array[mystack.top()]) mystack.pop();
		if(array[i]>=array[mystack.top()]){
			temp=-1;
			mystack.pop();
		}else temp=mystack.top();
		printf("%d %d\n",array[i],i-temp);
		mystack.push(i);
	}
}
int main(){
	int i;	//loop variable
	int n;	//no of elements
	IN(n);
	int *array=new int[n];
	FOR(i,n)
		IN(array[i]);
	stockspan(array,n);
	
}
