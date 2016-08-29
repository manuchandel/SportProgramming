#include <bits/stdc++.h>
#define ll long long
#define MAX 1000001
#define mod 1000000007
using namespace std;
struct Point{
    int x,y;
    int i;
};

// counter clockwise
int CCW(Point p1, Point p2, Point p3){
    long orientation=(long)(p2.y-p1.y)*(long)(p3.x-p1.x)-(long)(p3.y-p1.y)*(long)(p2.x-p1.x);

    // ccw
    if(orientation<0)
        return 1;

    // cloclwise
    else if(orientation>0)
        return -1;

    // colllinear
    return 0;
}
double dist(Point p1, Point p2){
    double d=(p1.y-p2.y);
    double e=(p1.x-p2.x);
    return (double)sqrt(d*d+e*e);
}
Point basepoint;
bool comp(Point p1, Point p2){
    int orientation=CCW(basepoint,p1,p2);
    if(orientation>0)
        return 1;
    else if(orientation<0){
        return 0;
    }
    else {
        return (dist(p1,basepoint)>dist(p2,basepoint));
    }
}
Point nextToTop(stack<Point> &mystack){
    Point p=mystack.top();
    mystack.pop();
    Point q=mystack.top();
    mystack.push(p);
    return q;
}
vector<Point> gharamscan(Point points[],int N){
    if(N==1){
        vector<Point> v;
        v.push_back(points[0]);
        return v;
    }
    int i;
    int index=-1;
    Point bottomMostLeft;

    bottomMostLeft.x=INT_MAX;
    bottomMostLeft.y=INT_MAX;

    // find bottomMostLeft point
    for(i=0;i<N;i++){
        if(bottomMostLeft.y>points[i].y){
            bottomMostLeft=points[i];
            index=i;
        }else if(bottomMostLeft.y==points[i].y){
            if(bottomMostLeft.x>points[i].x){
                bottomMostLeft=points[i];
                index=i;
            }
        }
    }
    swap(points[index],points[N-1]);
    basepoint=bottomMostLeft;
    sort(points,points+N-1,comp);
    vector<Point> final_points;
    final_points.push_back(points[0]);

    for(i=1;i<N-1;i++){
        if(CCW(basepoint,final_points[final_points.size()-1],points[i])==0){
            //cout<<points[i].x<<" "<<points[i].y<<endl;
        }
        else{
            final_points.push_back(points[i]);
        }
    }
    //cout<<endl<<endl;
    final_points.push_back(basepoint);
    N=final_points.size();
    stack<Point> mystack;
    mystack.push(final_points[N-1]);
    mystack.push(final_points[0]);
    mystack.push(final_points[1]);

    for(i=2;i<N;i++){
        while(CCW(nextToTop(mystack),mystack.top(),final_points[i])!=1) mystack.pop();
        mystack.push(final_points[i]);
    }
    vector<Point> v;

    while(!mystack.empty()){
        v.push_back(mystack.top());
        mystack.pop();

    }
    
    int n=v.size();
    
    for(i=0;i<n/2;i++){
       
        swap(v[i],v[n-1-i]);
    }

    return v;

}

void solve(Point points[],int N){
    if(N==1){
        printf("0.00\n");
        printf("%d\n",points[0].i);
        return;
    }
    int i;
    vector<Point> v=gharamscan(points,N);
    //cout<<"swapped"<<endl;
    Point basepoint=v[0];
    double sum=0.0;
    int n=v.size();
    for(i=0;i<n-1;i++){
        sum+=dist(v[i],v[i+1]);
    }
    if(v[0].i==v[n-1].i){
        v.pop_back();
    }else sum=sum*2;
    n=v.size();
    printf("%0.2lf\n",sum);
    printf("%d",v[0].i);
    for(i=1;i<n;i++){
        printf(" %d",v[i].i);
    }
    printf("\n");

}
int main(){
    int N,i,t,x,y,k;
    Point points[100000];
    scanf("%d",&t);
    while(t--){
        unordered_map<int,unordered_map<int,int>> mymap;
        scanf("%d",&N);
        k=0;
        for(i=0;i<N;i++){

            scanf("%d%d",&x,&y);
            if(mymap.find(x)==mymap.end() || mymap[x].find(y)==mymap[x].end()){
                points[k].x=x;
                points[k].y=y;
                points[k].i=i+1;
                k++;
                mymap[x][y]=i+1;
            }

        }

        solve(points,k);
        printf("\n");
    } 
    
    

}
