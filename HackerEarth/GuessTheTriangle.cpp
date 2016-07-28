#include <bits/stdc++.h>
using namespace std;

struct Point{
	float x;
	float y;
};

bool comp(Point p1, Point p2){
	if(p1.x<p2.x)
		return 1;
	else if(p1.x > p2.x)
		return 0;
	else{
		if(p1.y<p2.y)
			return 1;
		return 0;
	}
	
}
float foo(float a,float b,float c){
	return a+b-c;
}
int main()
{
   int i;
   Point p[3];
   Point arr[3];
   	for(i=0;i<3;i++){
   		scanf("%f%f",&p[i].x,&p[i].y);
   	}
   	for(i=0;i<3;i++){
   		arr[i].x=foo(p[i%3].x,p[(i+1)%3].x,p[(i+2)%3].x);
   		arr[i].y=foo(p[i%3].y,p[(i+1)%3].y,p[(i+2)%3].y);
   	}
   	
   	sort(arr,arr+3,comp);
   	for(i=0;i<3;i++)
   		printf("%0.4f %0.4f\n",arr[i].x,arr[i].y);
}
