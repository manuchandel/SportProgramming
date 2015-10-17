#include <stdio.h>
using namespace std;
int min(int a,int b){
	if(a<b)
		return a;
	return b;
}
int palindrome(char* s,int n){
	int i,j,k,*c;
	int *a=new int[n];
	int *b=new int[n];
	for(i=0;i<n;i++){
		a[i]=0;
		b[i]=0;
	}
	for(j=1;j<n;j++){
		k=j;
		for(i=0;i<n-j;i++){
			if(s[i]==s[k]){
				b[i]=b[i+1];
			}else{
				b[i]=1+min(a[i],a[i+1]);
			}
			k++;
		}
		c=a;
		a=b;
		b=c;
	}
	return a[0];
}
int main(){
	char s[5001];
	int n,i;
		scanf("%d",&n);
		scanf("%s",s);
		printf("%d\n",palindrome(s,n));

}
