/*
 *Given an array A of integers,
 *find the index of values that satisfy A + B = C + D,
 *where A,B,C & D are integers values in the array
 *A[A1] + A[B1] = A[C1] + A[D1]
 *A1 < B1, C1 < D1
 *A1 < C1, B1 != D1, B1 != C1 
 */
struct Pairs{
    int x,y;
};
Pairs setP(int a,int b){
    Pairs pair{a,b};
    return pair;
}
vector<int> Solution::equal(vector<int> &A) {
    unordered_map<int,vector<Pairs>> mymap;
    int i,j;
    int n=A.size();
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(mymap[A[i]+A[j]].size()==1){
                if(mymap[A[i]+A[j]][0].x != i && mymap[A[i]+A[j]][0].y!=j && mymap[A[i]+A[j]][0].y!=i ){
                    mymap[A[i]+A[j]].push_back(setP(i,j)); 
                }
                   
            }else if(mymap[A[i]+A[j]].size()==0)
                mymap[A[i]+A[j]].push_back(setP(i,j));
        }
    }
    auto it=mymap.begin();
    vector<int> ans(4,INT_MAX);
    while(it!=mymap.end()){
        if(it->second.size()>=2){
            if(it->second[0].x<ans[0]){
                ans[0]=it->second[0].x;
                ans[1]=it->second[0].y;
                ans[2]=it->second[1].x;
                ans[3]=it->second[1].y;
            }
            else if(it->second[0].x==ans[0] && it->second[0].y<ans[1]){
                ans[1]=it->second[0].y;
                ans[2]=it->second[1].x;
                ans[3]=it->second[1].y;
            }
            
            else if(it->second[0].x==ans[0] && it->second[0].y==ans[1] && it->second[1].x<ans[2]){
                ans[2]=it->second[1].x;
                ans[3]=it->second[1].y;
            }
            
            else if(it->second[0].x==ans[0] && it->second[0].y==ans[1] && 
            it->second[1].x==ans[2] && it->second[1].y<ans[3]){
                ans[3]=it->second[1].y;
            }
        }
        it++;
    }
    if(ans[0]!=INT_MAX)
        return ans;
   while(!ans.empty())
    ans.pop_back();
    return ans;
}
