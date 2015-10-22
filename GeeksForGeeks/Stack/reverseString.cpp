/*
 *Reverse a string using stack
 *Time=O(n) & space =O(n)
 */
#include <cstdio>
#include <stack>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
void reverse(char *buffer){
	stack <int> mystack;
	int i=0;	//loop variable
	while(buffer[i]!='\0'){
		mystack.push(buffer[i]);
		i++;
	}
	i=0;
	while(!mystack.empty()){
		buffer[i]=mystack.top();
		mystack.pop();
		i++;
	}
	buffer[i]='\0';
}
int main(){
	char buffer[101];
	scanf("%s",buffer);
	reverse(buffer);
	printf("%s\n",buffer);
}
