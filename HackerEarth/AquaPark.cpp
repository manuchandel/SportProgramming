#include <bits/stdc++.h>
using namespace std;
struct Point{
	int x;
	int y;
};

struct Segment{
	Point p1,p2;
	bool toconsider;
	Segment():toconsider(true){}
};

int index(int X,int Y,int N, Segment arr[]){
	int in=-1;
	int i;
	float y=(float)INT_MIN;
	for(i=0;i<N;i++){
		if(arr[i].toconsider){
			if(X<=max(arr[i].p1.x,arr[i].p2.x) &&X>=min(arr[i].p1.x,arr[i].p2.x )){
				float slope=(float)(arr[i].p2.y-arr[i].p1.y)/(arr[i].p2.x-arr[i].p1.x);
				float temp=(float)arr[i].p2.y+(float)slope*(X-arr[i].p2.x);

				if(temp>y && temp<=Y){
					y=temp;
					in=i;
				}
			}
		}
	}
	return in;
}
int main(){

	int X,N,i,Y=INT_MAX;
	scanf("%d%d",&X,&N);

	Segment arr[N];
	for(i=0;i<N;i++)
		scanf("%d%d%d%d",&arr[i].p1.x,&arr[i].p1.y,&arr[i].p2.x,&arr[i].p2.y);

	for(i=0;i<N;i++){
		if(arr[i].p1.y<arr[i].p2.y){
			Point p;
			p.x=arr[i].p1.x;
			p.y=arr[i].p1.y;
			arr[i].p1.x=arr[i].p2.x;
			arr[i].p1.y=arr[i].p2.y;
			arr[i].p2.x=p.x;
			arr[i].p2.y=p.y;
		}
			
	}
	int in=index(X,Y,N,arr);;
	while(in!=-1){
		
		X=arr[in].p2.x;
		Y=arr[in].p2.y;
		arr[in].toconsider=false;
		for(i=0;i<N;i++){
			if(arr[i].p2.y>Y)
				arr[i].toconsider=false;
		}
		in=index(X,Y,N,arr);
	}


	printf("%d\n",X );
}
