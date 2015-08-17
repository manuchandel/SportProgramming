/*
 *Given an array of integers, find two numbers such that they add up to a specific target number.
 *If multiple solutions exist, output the one where index2 is minimum.
 *If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.
 *if no pair exists, return empty list.
 */
vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int,vector<int>> mymap;
    vector<int> v;
    int index1=0,index2=INT_MAX;
    int i,j;
    for(i=0;i<A.size();i++)
        mymap[A[i]].push_back(i);
    int k;
    for(i=0;i<A.size();i++){
        k=B-A[i];
        if(mymap.find(k)!=mymap.end()){
            index1=i;
            index2=i;
            j=0;
            while(j<mymap[k].size()){
                if(mymap[k][j]!=i){
                    index2=mymap[k][j];
                    j=mymap[k].size();
                }
                j++;
            }
            if(index1<index2){
                if(v.empty()){
                    v.push_back(index1);
                    v.push_back(index2);
                    
                }else{
                    if(v[v.size()-1]>index2){
                        v.pop_back();v.pop_back();
                        v.push_back(index1);
                        v.push_back(index2);
                    }
                }
            }
        }
    }
    if(!v.empty()){
        v[0]++;
        v[1]++;
    }
    return v;
}
