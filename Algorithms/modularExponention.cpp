/*
 * complexity O(logb)
 */
long long modularExponention(long long a,long long b,long long m){
  long long x=1,y=a%m;
  while(b>0){
    if(b&1){
      x=(x*y);
      x%=m;
    }
    b=b>>1;
    y=y*y;
    y%=m;
  }
  return x;
}
