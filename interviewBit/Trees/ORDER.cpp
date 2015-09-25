
int createSegTree(int l,int r,int segI,int *tree){
    if(l==r){
        tree[segI]=1;
        return 1;
    }
    int mid=(l+r)>>1;
    tree[segI]=createSegTree(l,mid,2*segI+1,tree)+
        createSegTree(mid+1,r,2*segI+2,tree);
    return tree[segI];
}
int pos(int l,int r,int k,int segI,int *tree){
    if(l==r)
        return l;
    int left=tree[2*segI+1];
    int right=tree[2*segI+2];
    int mid=(l+r)>>1;
    if(k<left)
        return pos(l,mid,k,2*segI+1,tree);
    else
        return pos(mid+1,r,k-left,2*segI+2,tree);
}
void update(int l,int r,int k,int segI,int *tree){
    tree[segI]-=1;
    if(l==r)
        return;
    int mid=(l+r)>>1;
    if(k<=mid)
        update(l,mid,k,2*segI+1,tree);
    else update(mid+1,r,k,2*segI+2,tree);
}
struct Box{
    int a,b;
};
bool comp(Box b1,Box b2){
    if(b1.a<b2.a)
        return 1;
    return 0;
}
vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {
    int i,n=heights.size();
    Box *box=new Box[n];
    vector<int> v;
    for(i=0;i<n;i++){
        box[i].a=heights[i];
        box[i].b=infronts[i];
        v.push_back(0);
    }
    sort(box,box+n,comp);
    int *tree=new int[2220000];
    createSegTree(0,n-1,0,tree);
    for(i=0;i<n;i++){
       int j= pos(0,n-1,box[i].b,0,tree);
       v[j]=box[i].a;
       update(0,n-1,j,0,tree);
    }
    return v;
}
