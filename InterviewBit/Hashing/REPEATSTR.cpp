/*
 *Given a string,find the length of the longest substring without repeating characters.
 */
int Solution::lengthOfLongestSubstring(string A) {
    unordered_map <char,bool> mymap;
    int i;
    int maxLength=0;
    int currentLength=0;
    int p=0,q=0;
    int n=A.length();
    while(q<n){
        if(mymap.find(A[q])==mymap.end()){
            mymap[A[q]]=1;
            q++;
        }
        else{
           while(A[p]!=A[q]){
               mymap.erase(A[p]);
               p++;
           }
            if(p!=q){
               p++;
            }
            mymap.erase(A[q]);
            
        }
        currentLength=q-p;
        maxLength=max(maxLength,currentLength);
    }
    return maxLength;
    
}
