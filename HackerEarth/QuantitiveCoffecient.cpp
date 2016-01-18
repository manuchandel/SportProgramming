
#include <bits/stdc++.h>
#define mapping map
#define MAX_SETS 100000
#define mod 1000000007
using namespace std;

class Disjoint_Set_Union{
    public:
        Disjoint_Set_Union();   //constructor
        void reset();
        int find(int);
        void merge(int,int);
        

    private:
        int mymap[MAX_SETS];      //maximum sets
};
Disjoint_Set_Union :: Disjoint_Set_Union(){
    this->reset();
}

void Disjoint_Set_Union :: reset(){
    for(int i=0;i<MAX_SETS;i++)
        mymap[i]=i;
}
/* find the set of x*/
int Disjoint_Set_Union :: find(int x){

    int key=x; 
    int val=this->mymap[key];

    while(val!=key){    // finding the parent
        key=val;
        val=this->mymap[key];
    }

    int parent=key;

    key=x;
    val=this->mymap[key];

    /* Path Compression */
    while(val!=key){

        this->mymap[key]=parent;
        key=val;
        val=this->mymap[key];
    }
    return parent;
 }


/* union set x and set y*/
void Disjoint_Set_Union :: merge(int x, int y){

    int parent_x= this->find(x);
    int parent_y= this->find(y);

    if(parent_x != parent_y){
        this->mymap[parent_x]=parent_y;
    }

}

struct Edge{
    int v1,v2;
    int w;
    Edge():v1(0),v2(0),w(0){}
};
bool comp(Edge e1, Edge e2){
    if(e1.w>e2.w)
        return true;
    return false;
}
int main()
{
    int T,N,M;
    Edge edge;
    
    Disjoint_Set_Union dsu;
    int a,b,c,i;
    long long weight;
    scanf("%d",&T);
    while(T--){
        weight=1;
        scanf("%d%d",&N,&M);
        vector<Edge> v(M,edge);
        dsu.reset();
        for(i=0;i<M;i++)
            scanf("%d%d%d",&v[i].v1,&v[i].v2,&v[i].w);
        make_heap(v.begin(),v.end(),comp);
        i=1;
        while(i<N){
            pop_heap(v.begin(),v.end(),comp);
            edge=v[v.size()-1];
            //printf("Edge popped %d\n",edge.w);
            if(dsu.find(edge.v1)!=dsu.find(edge.v2)){
                weight=weight *(long long)edge.w;
                weight%=mod;
                i++;
            }
            dsu.merge(edge.v1,edge.v2);
            v.pop_back();
                
        }
        printf("%d\n",weight);
        v.clear();
        
    }
}
