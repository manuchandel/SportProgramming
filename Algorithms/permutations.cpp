/*
 *Generate All possible ppermutations of a string
 */

/* utility function that swaps two characters */
void swap(char &a,char &b){
  char c=a;
  a=b;
  b=c;
}
/* generates all possible permutations of the string */
void generatePermutations(string &s,vector<string> &v,int l){
  if(l==s.length()-1){
    v.push_back(s);
    return;
  }
  for(int i=l;i<s.length();i++){
    swap(s[l],s[i]);
    generatePermutations(s,v,l+1);
    swap(s[l],s[i]);
  }
}
/* returns all possible permutations of a string */
vector<string> permute(string s){
  vector<string> v;
  generatePermutations(s,v,0);
  for(int i=0;i<v.size();i++)
    cout<<v[i]<<endl;
  return v;
}
