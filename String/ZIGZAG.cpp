string Solution::convert(string A, int B) {
   int n=A.length();
   string temp="";
   if(B==1 || n==1)
    return A;
   int i=0;
   bool down=1;
   int index;
   for(i=1;i<=B;i++){
       index=i-1;
       if(i!=B)
        down=1;
        else down=0;
          while(index<n){
              temp+=A[index];
              if(down){
                index+=2*(B-i);
                if(i!=1)
                    down=0;
              }else{
                index=index+(i-1)*2;
                if(i!=B)
                    down=1;
              }
          }
    }
    return temp;
}
