#include <stdio.h>
#include <iostream>
#define maxLength 450
using namespace std;
class Stack{
	public:
		Stack():top(0){}
		void push(char c){
			s[top]=c;
			top++;
		}
		char look(){
			return s[top-1];
		}
		char pop(){
			if(top==0)
				return '\0';
			char c=s[top-1];
			top--;
			return c;
		}
		int getTop(){
			return top;
		}
		void print(){
			int i;
			for(i=0;i<top;i++)
				printf("%c",s[i]);
			printf("\n");
		}
		void reset(){
			top=0;
		}
	private:
		char s[maxLength];
		int top;
};
Stack operatorStack;
Stack operandStack;
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
        default :
            return -1;
    }
}
int rpn(string buffer){
	operatorStack.reset();
	operandStack.reset();
    int length=buffer.length();
    int i=0,j=0,k=0,p;
    char c;
    for(k=0;k<length;k++){
        if(buffer[k]-'a'<=25&&buffer[k]-'a'>=0){
            operandStack.push(buffer[k]);
        }else{
            if(operatorStack.getTop()==0||buffer[k]=='('){	//operand stack is empty
               operatorStack.push(buffer[k]);
            }
            else if(buffer[k]==')'){
            	c=operatorStack.pop();
            	while(c!='('){
            		operandStack.push(c);
            		c=operatorStack.pop();
            	}
            }
            else{
                while(priority(buffer[k])<priority(operatorStack.look())){
                    c=operatorStack.pop();
                    if(c!='\0')
                    	operandStack.push(c);
                }
                operatorStack.push(buffer[k]);
            }
        }
    }
    c=operatorStack.pop();
    while(c!='\0'){
        operandStack.push(c);
        c=operatorStack.pop();
    }
    operandStack.print();
    
}
int main(){
	int T;
	string s;
	scanf("%d",&T);
	while(T--){
		cin>>s;
		rpn(s);
	}
}
