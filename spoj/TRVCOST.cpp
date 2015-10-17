#include <cstdio>
#include <stdlib.h>
#include <limits.h>
#define maxV 501
#define ll long long
using namespace std;
bool neighbour[maxV];
class Node{
	public:
		Node():next(0),data(0){}
		Node *next;
		int data;
};
class Link{
	public:
		Link():head(0),tail(0){}
		void addNode(int);
		void deleteNode(Node* ,Node*);
		bool isEmpty();
		int returnMin();
		Node *head,*tail;
};
class Vertex{
	public:
		Vertex():edge(0),v(0),edgel(0){}
		Vertex *edge;
		int v;
		int edgel;
};
class Graph{
	public:
		Graph():head(0),tail(0),seen(false),weight(INT_MAX){}
		void addNode(int,int);
		Vertex *head,*tail;
		bool seen;
		ll weight;
};
Link linklist;
Graph graph[maxV];
bool Link::isEmpty(){
	if(!head)
		return true;
	return false;
}
void Link::addNode(int i){
	Node *newone=new Node();
	if(!this->head){
		head=newone;
		tail=newone;
	}else{
		tail->next=newone;
		tail=newone;
	}
	newone->data=i;
	newone=NULL;
	delete newone;
}
void Link:: deleteNode(Node *current,Node *previous){
	if(current==head&¤t==tail){
		head=tail=NULL;
	}
	else if(current==head){
		head=current->next;
		current->next=NULL;
	}
	else if(current==tail){
		tail=previous;
		previous->next=NULL;
	}
	else{
		previous->next=current->next;
		current->next=NULL;
	}
	delete current;
}
/*==this function returns the minimum index of all the nodes present in the list and deletes the minimum node==*/
int Link::returnMin(){
	Node *p,*q=NULL,*r=NULL,*s=NULL;
	p=this->head;
	int l;
	ll min=INT_MAX;
	while(p){
		if(graph[p->data].weight<min){
			min=graph[p->data].weight;
			l=p->data;
			q=p;
			s=r;
		}
		r=p;
		p=p->next;
	}
	this->deleteNode(q,s);
	return l;
}
void Graph:: addNode(int j,int l){
	Vertex *newone=new Vertex();
	if(!this->head){
		this->head=newone;
		this->tail=newone;
	}else{
		tail->edge=newone;
		tail=newone;
	}
	newone->v=j;
	newone->edgel=l;
	newone=NULL;
	delete newone;
}
void djikshtra(int s){
	Vertex *current;
	int i;
	ll k;
	graph[s].weight=0;
	linklist.addNode(s);
	while(!linklist.isEmpty()){
		i=linklist.returnMin();
		current=graph[i].head;
		while(current){
			k=graph[i].weight+current->edgel;
			if(k<graph[current->v].weight){
				graph[current->v].weight=k;
				if(!neighbour[current->v]){
					neighbour[current->v]=true;
					linklist.addNode(current->v);
				}
			}
			current=current->edge;
		}
		graph[i].seen=true;
	}
}
void initialize(){
	for(int i=0;i<maxV;i++)
		neighbour[i]=false;
}
int main(){
	int n,i,j,length,q;
	initialize();
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d",&i,&j,&length);
		graph[i].addNode(j,length);
		graph[j].addNode(i,length);
	}
	scanf("%d",&j);
	djikshtra(j);
	scanf("%d",&q);
	while(q--){
		scanf("%d",&i);
		if(graph[i].weight==INT_MAX)
			printf("NO PATH\n");
		else printf("%lld\n",graph[i].weight);
	}
}
