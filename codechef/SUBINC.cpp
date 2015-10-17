#include <cstdio>
long long subarray(int A[],int n){
  int i;
  int p=0,q=1;
  long long sum=0,count=0;
  while(q<n){
    if(A[q-1]>A[q]){
      sum=q-p;
      sum=sum*(sum+1);
      sum=sum>>1;
      count+=sum;
      p=q;
    }
    q++;
  }
  sum=q-p;
  sum=sum*(sum+1);
  sum=sum>>1;
  count+=sum;
  return count;
}
int main(){
  int N,T;
  int i;
  scanf("%d",&T);
  int A[100000];
  while(T--){
    scanf("%d",&N);
    for(i=0;i<N;i++)
      scanf("%d",&A[i]);
    printf("%lld\n",subarray(A,N));
  }
} 
