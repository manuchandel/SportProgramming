#include <iostream>
#include <stdio.h>
#include <queue>
#include <deque>
using namespace std;

int main()
{
	int n,temp,i,sec=0;
    queue<int> idealorder;
    deque<int> callingorder;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	scanf("%d",&temp);
    	callingorder.push_back(temp);
    }
    for(i=0;i<n;i++){
    	scanf("%d",&temp);
    	idealorder.push(temp);
    }
    while(!idealorder.empty()){
    	if(callingorder.front()==idealorder.front()){
    		callingorder.pop_front();
    		idealorder.pop();
    	}else{
    		temp=callingorder.front();
    		callingorder.pop_front();
    		callingorder.push_back(temp);
    	}
    	sec++;
    }
    printf("%d\n",sec);
    return 0;
}

