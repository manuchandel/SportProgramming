/*
 *Given an array of integers where each element represents the max number of steps that can be made forward from that element.
 *Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element).
 *If an element is 0, then cannot move through that element.
 *Time=O(n^2) & space=O(n)
 *recurrance equation:
 *steps=1+Min(minSteps(array[i+j]))j=1 to array[i]
 *{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} => 1->3->8->9
 *{5, 2, 3, 2, 2, 1, 20, 3} => 5->2->20->3
 */
#include <cstdio>
#include <queue>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
#define LOOP(a,b,c) for(a=b;a<c;a++)
using namespace std;
struct Jumps{
	int steps;
	int parent;
	void set(int a,int b){
		steps=a;
		parent=b;
	}
};
int minSteps(int *array,int n,queue<int> &path){
	Jumps aux[n];
	int i,j;	//loop variable
	FOR(i,n)
		aux[i].set(n,-1);	//initialize steps
	aux[n-1].steps=0;
	while(i>=0){
		j=1;
		while(j<n-i && j<=array[i]){
			if(aux[i].steps>1+aux[i+j].steps)
				aux[i].set(1+aux[i+j].steps,i+j);
			j++;
		}
		i--;
	}
	i=0;
	while(i>=0){	//push path into the queue
		path.push(i);
		i=aux[i].parent;
	}
	if(aux[0].steps>=n)
		aux[0].steps=-1;
	return aux[0].steps;
}
int main(){
	int n;
	int i;
	IN(n);
	int *array=new int[n];
	FOR(i,n)
		IN(array[i]);
	queue<int> path;  //this will contain indices of min jump path
	printf("Min Steps: %d\nPath:",minSteps(array,n,path));
	while(path.size()!=1){
		printf("%d->",path.front());
		path.pop();
	}
	printf("%d\n",path.front());
	path.pop();
}
