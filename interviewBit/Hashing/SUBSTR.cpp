/*
 *You are given a string, S, and a list of words, L, that are all of the same length.
 *Find all starting indices of substring(s) in S that is a concatenation of each word
 *in L exactly once and without any intervening characters.
 */
#define FOR(a,b) for(a=0;a<b;a++)
struct Pairs{
    int x,y;
};
Pairs setPair(int a,int b){
    Pairs pair{a,b};
    return pair;
}
bool checkSubstr(string s,int l,int m,unordered_map<string,Pairs> mymap){
    int n=s.length();
    string temp;
    int i=0;
    int count=0;
    auto it=mymap.begin();
    while(it!=mymap.end()){
        (it->second).y=0;
        it++;
    }
    while(i<=n-l){
        temp=s.substr(i,l);
        if(mymap.find(temp)==mymap.end())
            return 0;
        else{
            mymap[temp].y+=1;
            if(mymap[temp].y<=mymap[temp].x)
                count++;
            else return 0;
        }
        i+=l;
    }
    if(count==m)
        return 1;
    return 0;
}
vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int i,j;
    int n=A.length(),
        m=B.size();
    unordered_map <string,Pairs> mymap;
    FOR(i,m){
        if(mymap.find(B[i])==mymap.end())
            mymap[B[i]].x=1;
        else mymap[B[i]].x+=1;
    }
    int l=B[0].length();
    vector<int> v;
    if(n<l*m)
        return v;
    string s;
    i=0;
    while(i<=n-l*m){
        s=A.substr(i,l*m);
        if(checkSubstr(s,l,m,mymap))
        v.push_back(i);
        i++;
    }
    return v;
    
}
