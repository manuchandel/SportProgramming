/*
 * 1= xa+yb for the numbers a,b
 * x=a inverse mod b
 * y=b inverse mod a
 * Ax+By=GCD(A,B)=GCD(B,A%B)
 */
class ExtendedEuclid{
  public:
    ExtendedEuclid():x(0),y(0),gcd(0){}
    int aInverseModB(int,int);
    int getGcd(int,int);
  private:
    int x,y;
    int gcd;
    void calExtendedEuclid(int,int);
};
void ExtendedEuclid :: calExtendedEuclid(int A,int B){
  if(B==0){
    gcd=A;
    x=1;
    y=0;
    return;
  }
  calExtendedEuclid(B,A%B);
  int temp=x;
  x=y;
  y=temp-((int)(A/B))*y;
}
int ExtendedEuclid :: aInverseModB(int A,int B){
  calExtendedEuclid(A,B);
  if(gcd!=1)
    return -1;  //inverse do not exist
  if(x<0)
    return x+B;
  return x;
}
int ExtendedEuclid :: getGcd(int A,int B){
  calExtendedEuclid(A,B);
  return gcd;
}
