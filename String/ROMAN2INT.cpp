/* Given a roman numeral, convert it to an integer.*/
int value(char A){
    switch(A){
        case 'M' :
            return 1000;
        case 'D' :
            return 500;
        case 'C' :
            return 100;
        case 'L':
            return 50;
        case 'X' :
            return 10;
        case 'V' :
            return 5;
        case 'I' :
            return 1;
        default:
            return 0;
    }
}
int Solution::romanToInt(string A) {
    
   int previous=0;
   int current=0;
   int ans=0;
   int i=0;
   for(i=0;i<A.length();i++){
       current=value(A[i]);
       if(current>previous){
           ans=ans-2*previous;
       }
       ans+=current;
       previous=current;
   }
   return ans;
}
