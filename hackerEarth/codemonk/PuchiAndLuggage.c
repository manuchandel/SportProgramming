#include <stdio.h>
struct Box{
	int day;
	int weight;
	int ans;
};
void merge(struct Box A[],int l,int r){
	int mid=(l+r)>>1;
	struct Box Aux[r-l+1];
	int p=l,q=mid+1,i=0,j;
	while(p<=mid && q<=r){
		if(A[p].weight<A[q].weight){
			A[p].ans+=(q-mid-1);
			Aux[i]=A[p];
			p++;
		}else{
			Aux[i]=A[q];
			q++;
		}
		i++;			
	}
	while(p<=mid){
		A[p].ans+=(r-mid);
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
void split(struct Box A[],int l,int r){
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
	struct Box A[100000];
	int B[100000];
    scanf("%d",&T);
    while(T--){
    	scanf("%d",&n);
    	for(i=0;i<n;i++){
    		A[i].day=i;
    		A[i].ans=0;
    		scanf("%d",&(A[i].weight));
    	}
    	split(A,0,n-1);
    	for(i=0;i<n;i++)
    		B[A[i].day]=A[i].ans;
    	for(i=0;i<n;i++)
    		printf("%d ",B[i]);
    	printf("\n");
    }
    return 0;
}


