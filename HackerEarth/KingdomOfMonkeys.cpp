#include <bits/stdc++.h>
using namespace std;
class GraphNode{

	public:
		GraphNode();
		GraphNode *edge;
		int V;
};

GraphNode :: GraphNode(){
	edge=NULL;
	V=0;
}

class AdjList{

	public:
		AdjList();
		int color;
		GraphNode *head;
		GraphNode *tail;

};

AdjList:: AdjList(){
	head=NULL;
	tail=NULL;
	color=0;
}

class Graph{

	public:
		Graph();
		AdjList **adjlist;
		int N;
		void createGraph(int);
		void addEdge(int,int);
		void printGraph();
		void deleteGraph();


};

Graph :: Graph(){
	N=0;
}

void Graph::createGraph(int V){
	
	this->N=V;
	adjlist=new AdjList *[V];
	for(int i=0;i<V;i++)
		adjlist[i]=new AdjList();
	
}

void Graph::addEdge(int v1, int v2){
	GraphNode *graphnode=new GraphNode();
	graphnode->V=v2;
	int i=v1;
	if(adjlist[i]->head){
		adjlist[i]->tail->edge=graphnode;
		adjlist[i]->tail=graphnode;
	}else{
		adjlist[i]->head=graphnode;
		adjlist[i]->tail=graphnode;
	}
}

void Graph::printGraph(){
	GraphNode *current;
	for(int i=0;i<N;i++){
		current=adjlist[i]->head;
		cout<<i<<" ->";
		while(current){
			cout<<current->V<<" ->";
			current=current->edge;
		}
		cout<<"NULL"<<endl;
	}
}
void Graph::deleteGraph(){
	GraphNode *current=NULL;
	GraphNode *current_delete;
	for(int i=0;i<N;i++){
		current_delete=adjlist[i]->head;
		if(current_delete)
			current=current_delete->edge;
		while(current){
			delete current_delete;
			current_delete=current;
			current=current->edge;
		}
		delete current_delete;
	}
	for(int i=0;i<N;i++)
		delete adjlist[i];
	adjlist=NULL;
	N=0;
}
long long bfs(long long A[],int N, Graph graph){
	queue<int> Q;
	int i,j;
	long long local=0;
	long long global=0;
	for(i=0;i<N;i++){

		if(graph.adjlist[i]->color==0){
			graph.adjlist[i]->color=1;
			//cout<<"push "<<current->V<<endl;
			Q.push(i);
		}

		local=0;
		while(!Q.empty()){
			j=Q.front();
			Q.pop();
			GraphNode *current=graph.adjlist[j]->head;
			while(current){
				if(graph.adjlist[current->V]->color==0){
					graph.adjlist[current->V]->color=1;
					//cout<<"push "<<current->V<<endl;
					Q.push(current->V);
				}
					
				current=current->edge;
			}
			//cout<<"pop "<<j<<endl;
			local+=A[j];
		}
		global=max(global,local);
	}
	return global;
	
}
int main(){
	int T,N,M,x,y,i;
	scanf("%d",&T);
	long long A[100000];
	Graph graph;
	while(T--){
		scanf("%d%d",&N,&M);
		graph.createGraph(N);
		while(M--){
			scanf("%d%d",&x,&y);
			graph.addEdge(x-1,y-1);
			graph.addEdge(y-1,x-1);
		}
		for(i=0;i<N;i++)
			scanf("%lld",&A[i]);
		printf("%lld\n",bfs(A,N,graph));
		graph.deleteGraph();
	}
}
