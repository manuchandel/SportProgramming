/*
 *Given an expression string exp, 
 *write a program to examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
 *For example, the program should print true for exp = “[()]{}{[()()]()}” and false for exp = “[(])”
 *Time=O(n) & space =O(n)
 */
#include <cstdio>
#include <stack>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
bool checkBalancedParentheses(char *buffer){
	stack <char> mystack;
	int i=0;	//loop variable
	while(buffer[i]!='\0'){
		if(buffer[i]=='(' || buffer[i]=='{' || buffer[i]=='[')
			mystack.push(buffer[i]);
		else if(buffer[i]==')'){
			if(mystack.top()=='(')
				mystack.pop();
			else return false;
		}
		else if(buffer[i]=='}'){
			if(mystack.top()=='{')
				mystack.pop();
			else return false;
		}
		else if(buffer[i]==']'){
			if(mystack.top()=='[')
				mystack.pop();
			else return false;
		}
		i++;
	}
	if(mystack.empty())
		return true;
	return false;
}
int main(){
	char buffer[101];
	scanf("%s",buffer);
	if(checkBalancedParentheses(buffer))
		printf("parentheses are balanced\n");
	else printf("parentheses are not balanced\n");
}
