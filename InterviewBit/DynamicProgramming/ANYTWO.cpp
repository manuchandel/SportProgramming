
int Solution::anytwo(string A) {
   
    int n=A.length();
    int i,j;
    string B=A;
    int *arr=new int [n];
    memset(arr,0,sizeof(int)*n);
    for(i=1;i<n;i++){
        if(A[0]==A[i])
            arr[i]=1;
        else arr[i]=arr[i-1];
    }
    int diag=arr[0],temp;
    for(i=1;i<n;i++){
        diag=arr[0];
        if(A[i]==A[0])
            arr[0]=1;
        //printf("%d ",arr[0]);
        for(j=1;j<n;j++){
            temp=arr[j];
            if(A[j]==A[i] && j!=i)
                arr[j]=1+diag;
            else arr[j]=max(arr[j],arr[j-1]);
            diag=temp;
            //printf("%d ",arr[j]);
        }
        //printf("\n");
    }
    if(arr[n-1]>1)
        return 1;
    return 0;
    
}
