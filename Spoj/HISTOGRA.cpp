#include <iostream>
#include <cmath>
using namespace std;
long long maxAreaCrossingMidpoint(long long *a,long long left,long long right){
	long long leftArea=0,rightArea=0,midArea=0;
	long long i,j,mid=(left+right)/2;
	long long width=0,height=a[mid];
	for(i=mid;i>=left;i--){
		width=mid-i;
		height=min(a[i],height);
		leftArea=max(height*width,leftArea);
	}
	width=0;
	height=a[mid];
	for(i=mid;i<=right;i++){
		width=i-mid;
		height=min(a[i],height);
		rightArea=max(height*width,rightArea);
	}
	j=mid+1;	i=mid-1;	height=a[mid];	midArea=0;	width=1;
	while(j<=right&&i>=left){
		
		if(a[j]<a[i]){
			width++;
			height=min(a[i],height);
			midArea=max(midArea,width*height);
			i--;
		}else{
			width++;
			height=min(a[j],height);
			midArea=max(midArea,width*height);
			j++;
		}
	}
	while(j<=right){
		width++;
		height=min(a[j],height);
		midArea=max(height*width,midArea);
		j++;
	}
	while(i>=left){
		width++;
		height=min(a[i],height);
		midArea=max(height*width,midArea);
		i--;
	}
	return max(midArea,max(leftArea,rightArea));
}
long long maxAreaOfHistogram(long long *a,long long left,long long right){
	if(left==right)
		return a[left];
	long long mid=(left+right)/2;
	long long leftArea,rightArea,midArea;
	leftArea=maxAreaOfHistogram(a,left,mid);
	rightArea=maxAreaOfHistogram(a,mid+1,right);
	midArea=maxAreaCrossingMidpoint(a,left,right);
	return max(midArea,max(leftArea,rightArea));
}
int main(){
	long long n,i;
	long long *a=new long long [100000];
	while(1){
		cin>>n;
		if(n==0)
			break;
		for(i=0;i<n;i++)
			cin>>a[i];
		cout<<maxAreaOfHistogram(a,0,n-1)<<endl;
	}
}
