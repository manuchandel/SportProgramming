/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n. */
void paranthesis(vector<string> &s,string temp,int a,int n){
  if(a>n)
    return;
  if(a==0){
    while(n--)
      temp+=")";
    s.push_back(temp);
    return;
  }
  temp+='(';
  paranthesis(s,temp,a-1,n);
  temp[temp.length()-1]=')';
  paranthesis(s,temp,a,n-1);
}
vector<string> Solution::generateParenthesis(int A) {
    vector<string> s;
    string temp="";
    paranthesis(s,temp,A,A);
    return s;
}

