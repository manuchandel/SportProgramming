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
		int out_degree;
		GraphNode *head;
		GraphNode *tail;

};

AdjList:: AdjList(){
	out_degree=0;
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
void dfs(Graph &graph,int i,int &count){
	GraphNode *current=graph.adjlist[i]->head;
	count+=1;
	graph.adjlist[i]->color=1;
	while(current){
		if(graph.adjlist[current->V]->color==0){
			dfs(graph,current->V,count);
		}
		current=current->edge;
	}

}
int minFriends(Graph &graph,int N){
	int global=INT_MAX;
	int count=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			graph.adjlist[j]->color=0;
		count=0;
		dfs(graph,i,count);
		if(count>0)
			global=min(global,count);
	}
	return global;
}
int main(){
	int N,D,x,y;
	Graph graph;
	scanf("%d%d",&N,&D);
	graph.createGraph(N);
	while(D--){
		scanf("%d%d",&x,&y);
		graph.addEdge(x-1,y-1);
	}
	printf("%d\n",minFriends(graph,N));
	graph.deleteGraph();
}