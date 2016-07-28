#include <bits/stdc++.h>
using namespace std;
struct Point{
	long long x,y;
};
long long gcd(long long a,long long b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
long long foo(Point p1, Point p2){
	long long a=abs(p2.y-p1.y);
	long long b=abs(p2.x-p1.x);
	return gcd(a,b)-1;
	
}
int main()
{
    int N,i;
    scanf("%d",&N);
    Point arr[N];
	for(i=0;i<N;i++)
		scanf("%lld%lld",&arr[i].x,&arr[i].y);
	
	long long area=0;
	long long onsides=0;
	
	for(i=0;i<N-1;i++)
		area=area+arr[i].x*arr[i+1].y-arr[i+1].x*arr[i].y;
	area+=arr[N-1].x*arr[0].y-arr[0].x*arr[N-1].y;
	area=abs(area);
	area=area>>1;
	for(i=0;i<N-1;i++){
		onsides+=foo(arr[i],arr[i+1]);
	}
	onsides+=foo(arr[N-1],arr[0]);
	//cout<<onsides<<" "<<area<<" "<<N;
	N+=onsides;
	N=N>>1;
	printf("%lld\n",area+1-N);
}
