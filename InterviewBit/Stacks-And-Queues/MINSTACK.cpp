/*
 *Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 */
struct Box{
    int value,count;
};
stack<int> mystack;
stack<Box> minstack;
MinStack::MinStack() {
   while(!mystack.empty())
    mystack.pop();
    while(!minstack.empty())
        minstack.pop();
}
Box setval(int a,int b){
    Box b1;
    b1.value=a;
    b1.count=b;
    return b1;
}
void MinStack::push(int x) {
    if(!minstack.empty()){
        if(x<minstack.top().value)
            minstack.push(setval(x,0));
        else if(x==minstack.top().value)
            minstack.top().count+=1;
    }else minstack.push(setval(x,0));
    mystack.push(x);
}

void MinStack::pop() {
    if(!mystack.empty()){
        if(mystack.top()==minstack.top().value){
            if(minstack.top().count==0)
                minstack.pop();
            else minstack.top().count-=1;
        }
        mystack.pop();
    }
}

int MinStack::top() {
    if(!mystack.empty())
        return mystack.top();
    return -1;
}

int MinStack::getMin() {
    if(!minstack.empty())
        return minstack.top().value;
    else return -1;
}

