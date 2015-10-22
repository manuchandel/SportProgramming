/*
 *Reverse a stack using recursion
 *You are not allowed to use loop constructs like while, for..etc, and you can only use the following ADT functions on Stack S:
 *isEmpty(S) push(S) pop(S)
 *Time=O(n^2)  & space=O(1)
 *
 */
#include <cstdio>
#include <stack>
#include <ctime>
#include <cstdlib>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
stack <int> mystack;
/* function to print stack top to bottom*/
void printStack(){
	int temp=mystack.top();
	mystack.pop();
	printf("%d\n",temp);
	if(mystack.empty()){
		mystack.push(temp);
		return;
	}
	printStack();
	mystack.push(temp);
}
/*
 *use function call mystack.push(insertAtBottom(element)) to use this method 
 *This funxtion inserts elements at bottom
 *First 4 is inserted at the bottom.
    4 <-- top

 *Then 3 is inserted at the bottom
    4 <-- top    
    3

 *Then 2 is inserted at the bottom
    4 <-- top    
    3 
    2
     
 *Then 1 is inserted at the bottom
    4 <-- top    
    3 
    2
    1
 */

int insertAtBottom(int element){
	int temp=mystack.top();
	mystack.pop();
	if(mystack.empty()){
		mystack.push(element);
	}else mystack.push(insertAtBottom(element));
	return temp;
}
/* reverses stack */
void reverseStack(){
	if(mystack.size()==1)
		return;
	int temp=mystack.top();
	mystack.pop();
	reverseStack();
	mystack.push(insertAtBottom(temp));
}
int main(){
	srand(time(0));
	int i;	//loop variable
	FOR(i,5)
		mystack.push(rand()%1000);
	printStack();
	reverseStack();
	printf("\n");
	printStack();
	
}
