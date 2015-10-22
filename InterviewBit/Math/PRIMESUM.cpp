/* Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.*/

vector<int> Solution::primesum(int A) {
    vector<int> B;
    int i,j;
    int root=sqrt(A);
    bool *array=new bool[A+1];
    for(i=0;i<=A;i++)
        array[i]=0;
    for(i=2;i<=root;i++){
        if(array[i]==0)
            for(j=i;j<=A/i;j++)
                array[i*j]=1;
    }
    for(i=2;i<A;i++)
        if(!array[i] && !array[A-i]){
            B.push_back(i);
            B.push_back(A-i);
            return B;
        }
    
}
