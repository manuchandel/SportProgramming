/*
 *Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and 
 *an additional operation getMin() which should return minimum element from the SpecialStack.
 *All these operations of SpecialStack must be O(1). To implement SpecialStack,
 you should only use standard Stack data structure and no other data structure like arrays, list, .. et
 *Time=O(1) for each query & Worst space=O(n)
 */
#include <cstdio>
#define max 100
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
template <class T> class Stack{
	public:
		Stack():ptr(-1){}
		void push(T);
		void pop();
		bool empty();
		T top();
	protected:
		int ptr;
		T array[max];
};
template <class T> void Stack<T>:: push(T x){
	ptr++;
	array[ptr]=x;
}
template <class T> void Stack<T>:: pop(){
	ptr--;
}
template <class T> T Stack<T>:: top(){
	return array[ptr];
}
template <class T> bool Stack<T>:: empty(){
	if(ptr==-1)
		return true;
	return false;
}
template <class T> class SpecialStack :public Stack<T>{
	public:
		SpecialStack():Stack <int>(){}
		Stack <T> min;
		void push(T);
		void pop();
		T getMin();
};
template <class T> void SpecialStack<T>:: push(T x){
	this->ptr+=1;
	this->array[this->ptr]=x;
	if(min.empty()||min.top()>=x)
		min.push(x);
}
template <class T> void SpecialStack<T>:: pop(){
	if(min.top()==this->top())
		min.pop();
	this->ptr-=1;
}
template <class T> T SpecialStack<T>:: getMin(){
	return min.top();
}
int main(){
	SpecialStack <int> mystack;
	mystack.push(18);
	printf("%d\n",mystack.getMin());
	mystack.push(19);
	printf("%d\n",mystack.getMin());
	mystack.push(29);
	printf("%d\n",mystack.getMin());
	mystack.push(15);
	printf("%d\n",mystack.getMin());
	mystack.push(16);
	printf("%d\n",mystack.getMin());
	mystack.push(15);
	printf("%d\n",mystack.getMin());
	mystack.pop();
	printf("%d\n",mystack.getMin());
	mystack.pop();
	printf("%d\n",mystack.getMin());
	mystack.pop();
	printf("%d\n",mystack.getMin());
	mystack.pop();
	printf("%d\n",mystack.getMin());
}
