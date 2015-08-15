/*
 *Given an array A of integers and another integer k,
 *find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
 */
int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_map <int,int> mymap;
    int k=B;
    for(int i=0;i<A.size();i++)
        mymap[A[i]]=i;
    int temp;
    for(int i=0;i<A.size();i++){
        if(mymap.find(A[i]+k)!=mymap.end()){
            if(mymap[A[i]+k]!=i)
                return 1;
        }else if(mymap.find(A[i]-k)!=mymap.end()){
            if(mymap[A[i]-k]!=i)
                return 1;
        }
    }
    return 0;
    
}
