#include <iostream>
using namespace std;
double interestGreaterThanCent(double a)
{
	int b=100*a;
	return (double)b/100;
}
double interest(double a,double b)
{
	return interestGreaterThanCent((double)a*b/100);
}

void computeCompoundInterest(double a,double b,int c,int j,double d)
{
	int n1=(int)a;
	double frac=a-n1;
	int m=a;
	double fraction=frac;
	double intrst;
	for(int i=0;i<c;i++)
	{
		intrst=interest(a,b);
		a+=intrst;
		m=(int)a;
		fraction=a-m;		
	}
	float n=100*fraction;
	float o1=(int)100*frac;
	printf("%s" "%d" "%s" "%d" "%s" "%02.0f" "%s" "%.2f" "%s" "%d" "%s" "%d" "%s" "%02.0f" "\n","Case ",j,". $",
					n1,".",o1," at ",d,"% APR compounded ",c," times yields $",m,".",n);
}
	

int main()
{
	int i=1;
	while(1)
	{
		double a, b,d;
		int c;
		cin>>a>>b>>c;
		if(a==0&&b==0&&c==0)
		break;
		d=(double)b/c;
		computeCompoundInterest(a,d,c,i,b);
		i++;
	}
}
	
	


