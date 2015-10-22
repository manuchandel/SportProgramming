/* implementing least recent used cache */
class Node{
    public:
        Node(int a,int b):left(0),right(0),val(a),k(b){}
        Node *left,*right;
        int val;
        int k;
};
class Dq{
    public:
        Dq():front(0),rear(0){}
        Node *front,*rear;
        Node* pushFront(int,int);
        void recentUsed(Node*);
        void print();
        void clear();
        int popBack();
};
void Dq::print(){
    Node *current=front;
    while(current){
        printf("%d %d -->",current->k,current->val);
        current=current->right;
    }
    printf("\n");
}
void Dq::clear(){
    Node *current=front;
    while(front){
        front=front->right;
        delete current;
        current=front;
    }
    front=rear=0;
}
Node* Dq::pushFront(int a,int b){
    Node *node=new Node(a,b);
    if(!front){
        front=node;
        rear=node;
    }else{
        front->left=node;
        node->right=front;
        front=node;
    }
    return node;   
}
int Dq::popBack(){
    Node *current=rear;
    int key=current->k;
    rear=rear->left;
    if(rear)
        rear->right=0;
    else front=0;
    current->left=0;
    delete current;
    return key;
    
}
void Dq::recentUsed(Node *current){
    if(!current)
        return;
    Node *prev=current->left;
    if(prev)
        prev->right=current->right;
    else return;
    Node *next=current->right;
    if(next)
        next->left=prev;
    if(rear==current)
        rear=current->left;
    rear->right=0;
    current->right=front;
    front->left=current;
    current->left=0;
    front=current;
}
unordered_map<int ,Node* > mymap;
int lrusize=0;
Dq dq;
LRUCache::LRUCache(int capacity) {
    lrusize=capacity;
    mymap.clear();
    dq.clear();
}
int LRUCache::get(int key) {
    if(mymap.find(key)==mymap.end())
        return -1;
    Node *current=mymap[key];
    dq.recentUsed(current);
    return dq.front->val;
}

void LRUCache::set(int key, int value) {
    int n=mymap.size();
    if(mymap.find(key)!=mymap.end()){
        Node *current=mymap[key];
        current->val=value;
        dq.recentUsed(current);
    }else{
        if(n>=lrusize)
            mymap.erase(dq.popBack());
        mymap[key]=dq.pushFront(value,key);
    }
}
