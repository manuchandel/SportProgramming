#include <cstdio>
#include <cmath>
#define gc getchar_unlocked
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main(){
	int T,x,r,n;
	char type,dir;
	scanint(T);
	while(T--){
		scanint(x);
		x--;
		r=ceil((double)x/5);
		n=x-((r-1)*5);
		if(r%2==0){
			if(n<4)
				dir='R';
			else dir='L';
			if(n==1||n==5)
				type='W';
			else if(n==2)
				type='M';
			else if(n==3||n==4)
				type='A';
			else;

		}else{
			if(n>2)
				dir='R';
			else dir='L';
			if(n==1||n==5)
				type='W';
			else if(n==4)
				type='M';
			else if(n==2||n==3)
				type='A';
			else;
		}
		if(x==0)
			printf("poor conductor\n");
		else printf("%d %c %c\n",r,type,dir);
	}
}
