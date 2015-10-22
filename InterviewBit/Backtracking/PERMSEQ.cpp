/*
 *The set [1,2,3,…,n] contains a total of n! unique permutations.
 *Given n and k, return the kth permutation sequence.
 */
int fact[13];
void permute(string &s,int n,int k,deque<int> &DQ){
    if(DQ.size()==0)
        return;
    auto it=DQ.begin();
    while(fact[n-1]<k){
        k-=fact[n-1];
        it++;
    }
    s.append(to_string(*it));
    DQ.erase(it);
    permute(s,n-1,k,DQ);
}
string Solution::getPermutation(int n, int k) {
    deque<int> DQ;
    int i;
    for(i=1;i<=n;i++)
        DQ.push_back(i);
    fact[0]=1;
    for(i=1;i<13;i++)
        fact[i]=fact[i-1]*i;
    string s="";
    auto it=DQ.begin();
    while(n>13){
        s.append(to_string(*it));
        n--;
        DQ.erase(it);
        it=DQ.begin();
    }
    permute(s,n,k,DQ);
    return s;
}
