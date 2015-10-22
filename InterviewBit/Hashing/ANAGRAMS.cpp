/*
 *Given an array of strings, return all groups of strings that are anagrams.
 */
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    int n=A.size();
    int i;
    vector<vector<int>> v;
    vector<string> B;
    unordered_map<string,vector<int>> mymap;
    string temp;
    for(i=0;i<n;i++){
        temp="";
        temp.append(A[i]);
        sort(temp.begin(),temp.end());
        B.push_back(temp);
    }
    for(i=0;i<n;i++)
        mymap[B[i]].push_back(i+1);
    auto it=mymap.begin();
    while(it!=mymap.end()){
        v.push_back(it->second);
        it++;
    }
    return v;
}
