/*
 *Evaluate a postfix operation
 *1) It supports only 4 binary operators ‘+’, ‘*’, ‘-‘ and ‘/’. 
 *It can be extended for more operators by adding more switch cases.
 *2) The allowed operands are only single digit operands.
 *The program can be extended for multiple digits by adding a separator like space between all elements (operators and operands) of given expression
 *Time=O(n) & space =O(n)
 */
#include <cstdio>
#include <stack>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
int operate(int x,int y,int prior){
	switch(prior){
		case 4:
			return y/x;
		case 3:
			return y*x;
		case 2:
			return y-x;
		default:
			return y+x;
	}
}
int priority(char c){
	switch(c){
		case '/':
			return 4;
		case '*':
			return 3;
		case '-':
			return 2;
		case '+':
			return 1;
		default :
			return -1;
	}
}
int evaluate(char *expression){
	stack <int> mystack;
	int i=0;	//loop variable
	int prior;	//holds priority value
	int x,y;	//temporary variables to evaluate
	while(expression[i]!='\0'){
		prior=priority(expression[i]);
		if(prior<0)
			mystack.push(expression[i]-'0');
		else {
			x=mystack.top();
			mystack.pop();
			y=mystack.top();
			mystack.pop();
			mystack.push(operate(x,y,prior));
		}
		i++;
	}
	return mystack.top();
}


int main(){
	char buffer[101];
	scanf("%s",buffer);
	printf("%d\n",evaluate(buffer));
}
