/*
 *Given an input string, reverse the string word by word.
 *Given s = "the sky is blue",
 *return "blue is sky the".
 */
void Solution::reverseWords(string &A) {
    stack<string> mystack;
   string temp="";
   int n=A.length();
   int i;
   for(i=0;i<n;i++){
      if(A[i]!=' '){
          while(i<n && A[i]!=' '){
              temp=temp+A[i];
              i++;
          }
          mystack.push(temp);
          temp="";
      }
   }
   temp="";
   while(mystack.size()!=1){
       temp=temp+mystack.top();
       mystack.pop();
       temp=temp+" ";
   }
   temp=temp+mystack.top();
   A="";
   A=A+temp;
}
