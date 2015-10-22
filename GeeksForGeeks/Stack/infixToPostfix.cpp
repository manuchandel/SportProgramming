/*
 *Convert Infix notation to postfix notation
 *Expressions contains variables a-z A-z 0-9
 *Expressions contains operands ^,/,*,+,-
 *Time=O(n) & space =O(n)
 */
#include <cstdio>
#include <stack>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
stack <char> aux;
stack <char> expres;
int priority(char c){
	switch(c){
		case '^':
			return 5;
		case '/':
			return 4;
		case '*':
			return 3;
		case '-':
			return 2;
		case '+':
			return 1;
		case '(':
			return 0;
		case ')':
			return 0;
		default :
			return -1;
	}
}
void insert(char c,int prior){
	if(c==')'){
		while(aux.top()!='('){
			expres.push(aux.top());
			aux.pop();
		}
		aux.pop();
	}
	else if(c=='('|| aux.empty() || priority(aux.top()) < prior)
		aux.push(c);
	else{
		expres.push(aux.top());
		aux.pop();
		insert(c,prior);
	}
}
char* infixToPostfix(char *s){
	int i=0;	//loop variable
	int prior,n;
	char *postfix;
	while(s[i]!='\0'){
		prior=priority(s[i]);
		if(prior<0)
			expres.push(s[i]);
		else insert(s[i],prior);
		i++;
	}
	while(!aux.empty()){
		expres.push(aux.top());
		aux.pop();
	}
	n=expres.size();
	postfix=new char[n+1];
	FOR(i,n){
		postfix[n-i-1]=expres.top();
		expres.pop();
	}
	postfix[n]='\0';
	printf("%s\n",postfix );
	return postfix;
}


int main(){
	char buffer[101];
	scanf("%s",buffer);
	infixToPostfix(buffer);
}
