#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int main()
{
    int Q,type,cost;
    stack<int> mystack;
    scanf("%d",&Q);
    while(Q--){
    	scanf("%d",&type);
    	if(type==1){
    		if(mystack.empty())
    			printf("No Food\n");
    		else {
    			printf("%d\n",mystack.top());
    			mystack.pop();
    		}
    	}else{
    		scanf("%d",&cost);
    		mystack.push(cost);
    	}
    }
    return 0;
}

