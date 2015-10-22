#include <stdio.h>
void merge(int A[],int l,int r){
	int mid=(l+r)>>1;
	int Aux[r-l+1];
	int p=l,q=mid+1,i=0,j;
	while(p<=mid && q<=r){
		if(A[p]<=A[q]){
			Aux[i]=A[p];
			p++;
		}else{
			Aux[i]=A[q];
			q++;
		}
		i++;			
	}
	while(p<=mid){
		Aux[i]=A[p];
		i++;
		p++;
	}
	while(q<=r){
		Aux[i]=A[q];
		i++;
		q++;
	}
	for(j=0;j<i;j++){
		A[l]=Aux[j];
		l++;
	}
}
void split(int A[],int l,int r){
	if(l==r)
		return;
	int mid=(l+r)>>1;
	split(A,l,mid);
	split(A,mid+1,r);
	merge(A,l,r);
}
int main()
{
	int i,n,T;
	int A[100000];
    scanf("%d",&T);
    while(T--){
    	scanf("%d",&n);
    	for(i=0;i<n;i++)
    		scanf("%d",&A[i]);
    	split(A,0,n-1);
    	for(i=n-1;i>=0;i--)
    		printf("%d ",A[i]);
    	printf("\n");
    }
    return 0;
}

