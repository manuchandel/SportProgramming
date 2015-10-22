import java.util.*;
class VolumeOfTetrahedron {
	public static double roundoff( double n)
{
	return (n*10000+.49);
}
 
    public static void main(String[] args) {
    Scanner c=new Scanner(System.in);
    int t=c.nextInt();
    int z=0;
	while(z<t){
	z++;
	long u=c.nextLong();
	long V=c.nextLong();
	long W=c.nextLong();
	long w=c.nextLong();
	long v=c.nextLong(); 
	long U=c.nextLong();
	long c1,y,x,q,p,r,ab,ar,r1,r2,r3;
	double volume;
	c1=4*u*u*v*v*w*w;
	r1=v*v+w*w - U*U;
	r2=w*w+u*u - V*V;
	r3=u*u + v*v - W*W;
	r1=r1*r1;
	r2=r2*r2;
	r3=r3*r3;
	y=u*u*r1;
	x=v*v*r2;
	q=w*w*r3;
	p=(v*v +w*w - U*U);
	r=(w*w+u*u- V*V);
	ab=(u*u+v*v - W*W);
	ar=c1-y-x-q+p*r*ab;
	volume=(double)Math.sqrt(ar)/12;
	long n=(long)roundoff(volume);
    System.out.println((double)n/10000);
    }
}}


