/*
 *Implement K stacks in single array
 *push(),pop(),empty() all have O(1) time complexity
 */
#include <cstdio>
#include <limits.h>
#define max 1000
#define k 5
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
template <class T> class Kstacks{
	public:
		Kstacks();
		void push(T,int);
		void pop(int);
		T top(int);
		bool empty(int);
	private:
		T array[max];
		int topElement[k+1];
		int next[max];
};
template <class T> Kstacks<T> :: Kstacks(){
	int i;
	FOR(i,max)
		next[i]=i+1;
	FOR(i,k+1)
		topElement[i]=-1;
	topElement[0]=0;	// topElement[0] stores free nodes stack
	next[max-1]=-1;
}

template <class T>  void Kstacks<T>:: push(T a,int s){
	int freeIndex;	//stores index of free node in array
	freeIndex=topElement[0];
	if(freeIndex==-1){
		printf("%s\n","stack is full no more elements can be pushed");
		return;
	}
	topElement[0]=next[freeIndex];	//point top to next free index
	if(topElement[s]==-1){	//implies stack with number s is empty
		topElement[s]=freeIndex;
		next[freeIndex]=-1;	//now update the remaining free node
	}else {
		next[freeIndex]=topElement[s];
		topElement[s]=freeIndex;
		array[freeIndex]=a;
	}
	array[freeIndex]=a;	//push a on to the sno stack
}
template <class T>  void Kstacks<T>:: pop(int s){
	int poppingIndex=topElement[s];
	if(poppingIndex==-1){
		printf("%s\n","stack is empty no more elements can be popped");
		return;
	}
	topElement[s]=next[poppingIndex];
	next[poppingIndex]=topElement[0];	//point new free node to the top of freenode stack
	topElement[0]=poppingIndex;		//point top of the free node stack to new free node
}
template <class T>  T Kstacks<T>:: top(int s){
	if(topElement[s]==-1){
		printf("%s\n","stack is empty!! try pushing some elements");
		return INT_MIN;
	}
	else return array[topElement[s]];
}
template <class T>  bool Kstacks<T>:: empty(int s){
	if(topElement[s]==-1)
		return true;
	else return false;
}
int main(){
	Kstacks<int> s1;
	/* sample operations */
	s1.push(2,1);
	s1.push(3,1);
	s1.push(5,2);
	s1.push(7,1);
	s1.push(11,1);
	s1.push(13,1);
	s1.push(17,1);
	s1.push(10,2);
	s1.push(20,2);
	s1.push(30,2);
	s1.push(4,3);
	s1.push(16,3);
	s1.push(9,3);
	s1.push(25,3);
	s1.push(8,4);
	s1.push(27,4);
	s1.push(64,4);
	s1.push(101,5);
	s1.push(126,5);
	s1.push(135,5);
	s1.push(174,5);
	while(!s1.empty(1)){
		printf("%d\n",s1.top(1));
		s1.pop(1);
	}
}
