/*
 *For Given Number N find if its COLORFUL number or not
 *A number can be broken into different sub-sequence parts. 
 *Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
 *And this number is a COLORFUL number, since product of every digit of a sub-sequence are different
 */
int subNum(int l,unordered_map <int,int> &mymap,const vector<int> &A){
    int product=1;
    int i,p=0;
    for(i=0;i<l-1;i++)
        product*=A[i];
    
    for(i=l-1;i<A.size();i++){
        product*=A[i];
        if(mymap.find(product)!=mymap.end())
            return 0;
        else mymap[product]=1;
        product/=A[p];
        p++;
    }
    return 1;
}
int Solution::colorful(int A) {
    if(A<10)
        return 1;
    vector<int> array;
    int digit;
    while(A>0){
        digit=A%10;
        if(digit==0)
            return 0;
        array.push_back(digit);
        A=A/10;
    }
   unordered_map<int,int> mymap;
   for(int i=1;i<=array.size();i++)
    if(!subNum(i,mymap,array))
        return 0;
    return 1;
    
}
