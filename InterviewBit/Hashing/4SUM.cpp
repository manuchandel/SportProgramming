/*
 *Given an array S of n integers, are there elements a, b, c, and d in S such that
 *a + b + c + d = target ?
 *Find all unique quadruplets in the array which gives the sum of target.
 */
#define FOR(a,b,c) for(a=b;a<c;a++)
struct Pairs{
    int x,y;
};
Pairs setPair(int a,int b){
    Pairs pair{a,b};
    return pair;
}
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    unordered_map<int,vector<Pairs>> mymap;
    set<vector<int>> myset;
    vector<vector<int>> v;
    vector<int> row(4,0);
    sort(A.begin(),A.end());
    int i,j,n=A.size();
    FOR(i,0,n)
        FOR(j,i+1,n)
            mymap[A[i]+A[j]].push_back(setPair(i,j));
    int temp;
    while(mymap.size()>0){
        auto it=mymap.begin();
        temp=it->first;
        if(mymap.find(B-temp)!=mymap.end()){
            FOR(i,0,mymap[temp].size())
                FOR(j,0,mymap[B-temp].size()){
                    if(mymap[temp][i].x!=mymap[B-temp][j].x &&
                       mymap[temp][i].x!=mymap[B-temp][j].y &&
                       mymap[temp][i].y!=mymap[B-temp][j].x &&
                       mymap[temp][i].y!=mymap[B-temp][j].y){
                            row[0]=A[mymap[temp][i].x];
                            row[1]=A[mymap[temp][i].y];
                            row[2]=A[mymap[B-temp][j].x];
                            row[3]=A[mymap[B-temp][j].y];
                            sort(row.begin(),row.end());
                            myset.insert(row);
                       }
                }
        }
       mymap.erase(it);
    }
    auto it1=myset.begin();
    while(it1!=myset.end()){
        v.push_back(*it1);
        it1++;
    }
        
    return v;
    
}
