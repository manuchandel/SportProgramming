#include <bits/stdc++.h>
using namespace std;
struct T{
    int I,last,sec_last,z,p;
    T():I(0),last(0),sec_last(0),z(0),p(0){}
};
struct compare{
    bool operator()(T a, T b){
        if(a.z < b.z)
            return false;
        else if(a.z > b.z)
            return true;
        else{
            if(a.I < b.I)
                return false;
            else return true;
        }
    }
};
int main()
{
    priority_queue<T,vector<T>,compare> pq;
    int C,P,N,i,X;

    scanf("%d%d%d",&C,&P,&N);
    T carr[C];
    int parr[P];
    
    for(i=0;i<N;i++){
        scanf("%d",&X);
        carr[i].last=X;
        carr[i].z=X;
        carr[i].p=1;
    }
    for(i=0;i<C;i++){
        carr[i].I=i+1;
        pq.push(carr[i]);
    }
    for(i=0;i<P;i++)
        scanf("%d",&parr[i]);
    T temp; 
    for(i=0;i<P;i++){
        temp=pq.top();
        temp.p+=1;
        temp.sec_last=temp.last;
        temp.last=parr[i];
        temp.z=(temp.sec_last+temp.last)*temp.p;
        pq.pop();
        pq.push(temp);
        printf("%d ",temp.I);
    }
    printf("\n");
   
}
