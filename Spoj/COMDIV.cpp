#include <stdio.h>
#define N 1000001
using namespace std;
int *numbers=new int [N];
int *noOfFactors=new int [N];
int gcd(int a,int b){	//euclidean algorithm
	int temp;
	if(b>a){	//always a>b
		temp=a;
		a=b;
		b=temp;
	}
	while(b!=0){
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}
int retlog(int &a,int n){	//log a base n
	int count=0;
	while(a%n==0){
		count++;
		a/=n;
	}
	return count;
}
void sieve(){
	int i,j;
	bool array[N];
	for(i=0;i<N;i++){
		numbers[i]=i;
		noOfFactors[i]=1;
		array[i]=false;
	}
	for(i=2;i<N;i++){
		if(array[i]==false){
			for(j=i*2;j<N;j+=i){
				array[j]=true;
				noOfFactors[j]=noOfFactors[j]*(retlog(numbers[j],i)+1);
			}
		noOfFactors[i]=2;
		}
	}
}
int main(){
	int t,a,b;
	scanf("%d",&t);
	sieve();
	while(t--){
		scanf("%d%d",&a,&b);
		printf("%d\n",noOfFactors[gcd(a,b)]);
	}
}
