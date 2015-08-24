/*
 *Given a positive integer, return its corresponding column title as appear in an Excel sheet
 */

/*
 * 1 -> A
 *2 -> B
 *3 -> C
    ...
 *26 -> Z
 *27 -> AA
 *28 -> AB
 */
string Solution::convertToTitle(int A) {
    A;
   int maxPower=1;
   string s;
   int character;
   while(A >0){
       character=(A-1)%26;
       A=A-character-1;
       A/=26;
       character+=65;
       s=s+(char)character;
   }
   char c;
   int n=s.length();
   for(int i=0;i<n/2;i++){
       c=s[i];
       s[i]=s[n-1-i];
       s[n-1-i]=c;
   }
    
   return s;
   
}
