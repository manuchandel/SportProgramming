#include <iostream>
using namespace std;
int main()
{    
	char a2[4]={'6','2','4','8'};
	char a3[4]={'1','3','9','7'};
	char a4[2]={'6','4'};
	char a7[4]={'1','7','9','3'};
	char a8[4]={'6','8','4','2'};
	char a9[2]={'1','9'};
	int t,z=0;
    cin>>t;
    while(z<t){
		int a;
		int b;
		cin>>a;
		cin>>b;
		int s;
		if(a<10)
			s=a;
		else s=a%10;
		if(b>0){
			switch (s){
				case 0:
					cout<<0;
					break;
				case 1:
					cout<<1;
					break;
				case 2:
					cout<<a2[b%4];
					break;
				case 3:
					cout<<a3[b%4];
					break;
				case 4:
					cout<<a4[b%2];
					break;
				case 5:
					cout<<5;
					break;
				case 6:
					cout<<6;
					break;
				case 7:
					cout<<a7[b%4];
					break;
				case 8:
					cout<<a8[b%4];
					break;
				case 9:
					cout<<a9[b%2];
				default :break;
				}
			}
		if(b==0)
			cout<<1;
		cout<<endl;
		z++;
	}
}

