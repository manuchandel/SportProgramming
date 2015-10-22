/*
 *Find the largest continuous sequence in a array which sums to zero.
 */
struct Pair{
    int x,y;
};
vector<int> Solution::lszero(vector<int> &A) {
    int i,n=A.size();
    int sum=0;
    unordered_map<int,Pair> mymap;
    for(i=0;i<n;i++){
        sum+=A[i];
        if(mymap.find(sum)==mymap.end()){
            mymap[sum].x=i;
            mymap[sum].y=-1;
        }
        else mymap[sum].y=i;
    }
    auto it=mymap.begin();
    int mini=n,maxi=0;
    while(it!=mymap.end()){
        if(it->first==0){
            if(it->second.y!=-1)
                maxi=it->second.y;
            else maxi=it->second.x;
            mini=-1;
        }
        else if(it->second.y!=-1){
            if((it->second.y)-(it->second.x) > maxi-mini){
                maxi=it->second.y;
                mini=it->second.x;
            }else if((it->second.y)-(it->second.x)== maxi-mini && mini > it->second.x){
                mini=it->second.x;
                maxi=it->second.y;
            }
        }
        it++;
    }
    vector<int> ans;
    for(i=mini+1;i<=maxi;i++)
        ans.push_back(A[i]);
    return ans;
}
