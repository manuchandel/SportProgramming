/*
 *Create a data structure twoStacks that represents two stacks. 
 *Implementation of twoStacks should use only one array, i.e., both stacks should use the same array for storing elements.
 *Time=O(1) for all functions
 */
#include <cstdio>
#define max 100
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
template <class T>
class TwoStacks{
	public:
		TwoStacks():ptr1(-1),ptr2(max){}
		void push1(T);
		void push2(T);
		void pop1();
		void pop2();
		bool empty1();
		bool empty2();
		T top1();
		T top2();
	private:
		T array[max];
		int ptr1,ptr2;
};
template <class T>
void TwoStacks<T>:: push1(T x){
	ptr1++;
	array[ptr1]=x;
}
template <class T>
void TwoStacks<T>:: push2(T x){
	ptr2--;
	array[ptr2]=x;
}
template <class T>
void TwoStacks<T>:: pop1(){
	ptr1--;
}
template <class T>
void TwoStacks<T>:: pop2(){
	ptr2++;
}
template <class T>
bool TwoStacks<T>:: empty1(){
	if(ptr1==-1)
		return true;
	return false;
}
template <class T>
bool TwoStacks<T>:: empty2(){
	if(ptr2==max)
		return true;
	return false;
}
template <class T>
T TwoStacks<T>:: top1(){
	return array[ptr1];
}
template <class T>
T TwoStacks<T>:: top2(){
	return array[ptr2];
}
int main(){
	int i;	//loop variable
	TwoStacks <int> stack;
	/* sample operations */
	FOR(i,7)
		stack.push1(i);
	FOR(i,5)
		stack.push2(i*10);
	while(!stack.empty1()){
		printf("%d ",stack.top1());
		stack.pop1();
	}
	printf("\n");
	while(!stack.empty2()){
		printf("%d ",stack.top2());
		stack.pop2();
	}
	printf("\n");
}
