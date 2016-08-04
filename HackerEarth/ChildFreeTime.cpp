#include <bits/stdc++.h>
#define IN(L) scanf("%d",&L)
using namespace std;

struct Vertex{
	int v;
	int in;
	long long w;
	bool seen;
	Vertex *next;
	Vertex(){}
	Vertex(int a,int b,long long c,bool s, Vertex *n):v(a),in(b),w(c),seen(s),next(0){}
};
Vertex **tail=new Vertex*[1000001];
Vertex *v=new Vertex[1000001];

void add(int i,Vertex v1){
	tail[i]->next=(new Vertex(v1.v,v1.in,v1.w,v1.seen,v1.next));
	tail[i]=tail[i]->next;
}
long long dfs(int i){
	if(v[i].seen)
		return v[i].w;

	Vertex *head=v[i].next;
	long long a=0;
	while(head){

		a=max(a,head->w+2+dfs(head->v));
		head=head->next;
	}
	v[i].w=a;
	v[i].seen=true;
	return a;
}
int main(){
	int T,i,j,k,X,Y,N,M;
	long long C;
	IN(N);IN(M);
	for(i=0;i<=N;i++){
		v[i].v=i;
		v[i].in=0;
		v[i].w=0;
		v[i].seen=0;
		v[i].next=NULL;
		tail[i]=&v[i];
	}
	for(i=0;i<M;i++){
		IN(X);
		IN(Y);
		scanf("%lld",&C);
		Vertex v1(Y,0,C,false,0);
		add(X,v1);
		v[Y].in+=1;
	}
	long long ans=0;
	for(i=1;i<=N;i++)
		if(v[i].in==0)
			ans=max(ans,dfs(i));
	printf("%lld\n",ans);
}
