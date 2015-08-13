/*
 *Given a digit string, return all possible letter combinations that the number could represent.
 *A mapping of digit to letters (just like on the telephone buttons) is given below.
 */
string mapping(int d){
    switch(d){
        case 0:
            return "0";
        case 1:
            return "1";
        case 2:
            return "abc";
        case 3:
            return "def";
        case 4:
            return "ghi";
        case 5:
            return "jkl";
        case 6:
            return "mno";
        case 7:
            return "pqrs";
        case 8:
            return "tuv";
        case 9:
            return "wxyz";
        default:
            return "";
    }
}
void combinations(vector<string> &ans,vector<string> &container,string s,int i,int j){
    int n=container.size();
    if(i==n){
        ans.push_back(s);
        return;
    }
		s+="z";
    for(;j<container[i].size();j++){
        s[s.length()-1]=container[i][j];
        combinations(ans,container,s,i+1,0);
    }


}
vector<string> Solution::letterCombinations(string A) {
    string temp="";
    vector<string> container;
    vector<string> ans;
    for(int i=0;i<A.length();i++)
        container.push_back(mapping(A[i]-'0'));
    combinations(ans,container,temp,0,0);
    return ans;
}
