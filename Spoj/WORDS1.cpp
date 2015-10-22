#include <stdio.h>
#include <iostream>
#include <cstring>
#define maxV 26
using namespace std;
enum Color{
	white,grey,black
};
class Queue{
	public:
		Queue():front(0),back(-1){}
		void push(int a){
			back++;
			q[back]=a;
			
		}
		int pop(){
			int a=q[front];
			front++;
			return a;
		}
		bool isEmpty(){
			if(front>back)
				return true;
			return false;
		}
		void printQ(){
			for(int i=front;i<=back;i++)
				cout<<q[i]<<" ";
			cout<<endl;
		}
	private:
		int q[maxV];
		int front;
		int back;
	
};
class Vertex{
	public:
		Vertex():v(0),edge(0){}
		int v;
		Vertex *edge;
};
class Graph{
	public:
		Graph ():firstNode(0),lastNode(0), degree(0),color(white){}
		void addNode(int);
		void pushNeighbours(Queue*,Graph array[]);
		int degree;
		Color color;
		Vertex *firstNode;
		Vertex *lastNode;
};
void Graph::addNode(int n){
	Vertex *neighbourNode=new Vertex();
	if(!this->firstNode){
		firstNode=neighbourNode;
		lastNode=neighbourNode;
	}else{
		lastNode->edge=neighbourNode;
		lastNode=neighbourNode;
	}
	neighbourNode->v=n;
	this->degree=this->degree+1;
}
bool checkDegree(Graph array[]){
	int i,count=0;
	for(i=0;i<maxV;i++)
		if(array[i].degree%2!=0){
			count++;
		}
	if(count==0 || count==2)
		return true;
	return false;
}
void Graph::pushNeighbours(Queue *queue,Graph array[]){
	Vertex *current=this->firstNode;
	while(current){
		if(array[current->v].color==white){
			queue->push(current->v);
			array[current->v].color=grey;
		}
		current=current->edge;
	}
}
bool checkConnectedComponents(Graph array[],int totalVertex,int startVertex){
	int i,count=0;
	Queue *queue=new Queue;
	queue->push(startVertex);
	array[startVertex].color=grey;
	array[startVertex].pushNeighbours(queue,array);
	while(!queue->isEmpty()){
		i=queue->pop();
		array[i].color=black;
		count++;
		array[i].pushNeighbours(queue,array);
	}
	delete queue;
	if(count==totalVertex)
		return true;
	return false;

}
void print(Graph a[]){
	int i;
	for(i=0;i<maxV;i++){
		Vertex *current=a[i].firstNode;
		cout<<i<<" ";
		while(current){
			cout<<current->v<<" ";
			current=current->edge;
		}
		cout<<endl;
	}

}
bool method(int startingWordFrequency[],int endingWordFrequency[]){
	int i,j=0,a[26];
	for(i=0;i<maxV;i++){
		if(startingWordFrequency[i]!=endingWordFrequency[i]){
			a[j]=startingWordFrequency[i]-endingWordFrequency[i];
			j++;
		}		
	}
	if(j==2){
		if(a[0]+a[1]==0&&(a[0]==1||a[1]==1))
			return true;
	}
	if(j==0)
		return true;
	return false;
}
bool driver(){
	int T,N,i,j,vertexCount,startVertex;
	bool NumberOfVertex[maxV],flag;
	int startingWordFrequency[maxV];
	int endingWordFrequency[maxV];
	string s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		Graph array[maxV];
		flag=false;
		for(i=0;i<maxV;i++){
			NumberOfVertex[i]=false;
			startingWordFrequency[i]=0;
			endingWordFrequency[i]=0;
		}
		vertexCount=0;
		while(N--){
			cin>>s;
			i=s[0]-'0';
			i-=49;
			j=s[s.length()-1]-'0';
			j-=49;
			array[i].addNode(j);
			array[j].addNode(i);
			startingWordFrequency[i]+=1;
			endingWordFrequency[j]+=1;
			if(NumberOfVertex[i]==false){
				NumberOfVertex[i]=true;
				vertexCount++;
			}
			if(NumberOfVertex[j]==false){
				NumberOfVertex[j]=true;
				vertexCount++;
			}
		}
		if(checkDegree(array)&&checkConnectedComponents(array,vertexCount,i)&&method(startingWordFrequency,endingWordFrequency))
			printf("Ordering is possible.\n");
		else printf("The door cannot be opened.\n");
	}
}
int main(){
	
	driver();
}
