#include <bits/stdc++.h>
#define IN(L) scanf("%d",&L)
using namespace std;
int pos[10001];
struct Vertex{
	int v;
	long long w;
	Vertex(int a,long long b):v(a),w(b){}
};

bool comp(Vertex v1, Vertex v2){
	if(v1.w < v2.w)
		return 0;
	return 1;
}
void maintain(vector<Vertex> &v,int i){
	if(i>=v.size())
		return;
	int l=(i<<1)+1;
	int r=(i<<1)+2;
	//cout<<i<< " heap "<<l<<" "<<r<<endl;
	if(r<v.size()){
		if(v[i].w <=v[l].w and v[i].w<=v[r].w)
			return;
		else if(v[i].w >v[r].w and v[i].w<= v[l].w){
			//cout<<"worked 1"<<endl;
			pos[v[i].v]=r;
			pos[v[r].v]=i;
			swap(v[i],v[r]);
			maintain(v,r);
		}else if(v[i].w<=v[r].w and v[i].w>v[l].w){
			//cout<<"worked 2"<<endl;
			pos[v[i].v]=l;
			pos[v[l].v]=i;
			swap(v[i],v[l]);
			maintain(v,l);
		}else{
			if(v[r].w<v[l].w){
				//cout<<"worked 3"<<endl;
				pos[v[i].v]=r;
				pos[v[r].v]=i;
				swap(v[i],v[r]);
				maintain(v,r);
			}
			else{
				//cout<<"worked 4"<<endl;
				pos[v[i].v]=l;
				pos[v[l].v]=i;
				swap(v[i],v[l]);
				maintain(v,l);
			}
		}
	}
	else if(l<v.size()){
		if(v[i].w>v[l].w){
			
			pos[v[i].v]=l;
			pos[v[l].v]=i;
			swap(v[i],v[l]);
			maintain(v,l);
		}
	}

}
Vertex pop(vector<Vertex> &v){
	Vertex v1=v[0];
	
	pos[v[0].v]=v.size()-1;
	pos[v[v.size()-1].v]=0;
	swap(v[0],v[v.size()-1]);
	v.pop_back();
	maintain(v,0);
	return v1;
}
void maintainup(vector<Vertex> &v,int i){
	if(i<=0)
		return;
	int parent;
	if(i&1){
		parent=(i-1)>>1;
	}else parent=(i-2)>>1;

	if(v[parent].w>v[i].w){
		
		pos[v[parent].v]=i;
		pos[v[i].v]=parent;
		swap(v[parent],v[i]);
		maintainup(v,parent);
	}
}
void replace(vector<Vertex> &v,int k,long long w){
	if(v.size()==0)
		return;

	int i=pos[k];
	
	
	if(v[i].w<w)
		printf("Wrong Execution\n");
	v[i].w=w;
	
	maintainup(v,i);


}
void print(vector<Vertex> &v){
	for(int i=0;i<v.size();i++)
		cout<<"("<<v[i].v<<","<<v[i].w<<")"<<" ";
	cout<<endl<<endl;
}
void print(int N){
	for(int i=0;i<=N;i++)
		cout<<pos[i]<<" ";
	cout<<endl<<endl;
}
int main(){
	int T,i,j,k,X,Y,C,Q;
	IN(T);
	while(T--){
		int N,M;
		IN(N);
		IN(M);
		vector<vector<Vertex> > v;

		vector<Vertex> pq;
		for(i=0;i<=N;i++){
			vector<Vertex> t;
			t.push_back(Vertex(i,INT_MAX));
			v.push_back(t);
			pq.push_back(Vertex(i,INT_MAX));
		}

		for(i=0;i<M;i++){
			IN(X);IN(Y);IN(C);
			v[X].push_back(Vertex(Y,C));
			v[Y].push_back(Vertex(X,C));
		}
		v[1][0].w=0;
		//for(i=1;i<=N;i++)
			//print(v[i]);
		pq[1].w=0;
		make_heap(pq.begin(),pq.end(),comp);
		
		for(i=0;i<pq.size();i++)
			pos[pq[i].v]=i;
		//print(pq);
		
		for(i=1;i<=N;i++){
			//cout<<"pop"<<endl;
			Vertex vertex=pop(pq);
			//print(pq);
			//print(N);
			//cout<<"popped"<<endl;
			

			k=vertex.v;
			//cout<<k<<endl;
			//print(pq);
			for(j=1;j<v[k].size();j++){
				//cout<<v[k][j].v<<" "<<v[v[k][j].v][0].w <<" "<<vertex.w<<endl;
				if(v[v[k][j].v][0].w > v[k][j].w+vertex.w){
					v[v[k][j].v][0].w=v[k][j].w+vertex.w;
					replace(pq,v[k][j].v,v[k][j].w+vertex.w);

				}
			}

		}
		IN(Q);
			//cout<<"scanned Q"<<endl;
		for(i=0;i<Q;i++){
			IN(X);IN(Y);
			//cout<<i<<endl;
			printf("%lld\n",max((long long)0,Y-(v[X][0].w)*2) );
		}


	}

}
