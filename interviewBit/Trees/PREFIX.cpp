struct Trie{
    Trie* edges[26];
    int words;
    Trie(){
        for(int i=0;i<26;i++)
            edges[i]=0;
        words=0;
    }
};
void addToTrie(Trie *head,string s){
    int n=s.length();
    Trie *current=head;
    int i;
    for(i=0;i<n;i++){
        current->words+=1;
        if(!current->edges[s[i]-'a'])
            current->edges[s[i]-'a']=new Trie();
        current=current->edges[s[i]-'a'];
    }
}
string findprefix(string s, Trie *head){
    string pfx="";
    Trie *current=head;
    int i=0,n=s.length();
    current=current->edges[s[i]-'a'];
    pfx+=s[i];
    for(i=1;i<n;i++){
        if(current->words==1)
            return pfx;
        current=current->edges[s[i]-'a'];
        pfx+=s[i];
    }
    return pfx;
    
}
vector<string> Solution::prefix(vector<string> &A) {
    vector<string> v;
    Trie *head=new Trie();
    for(int i=0;i<A.size();i++)
        addToTrie(head,A[i]);
    for(int i=0;i<A.size();i++)
       v.push_back(findprefix(A[i],head));
     return v;
        
    
}
