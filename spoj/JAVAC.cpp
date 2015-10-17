#include <stdio.h>
#include <iostream>
#define maxLength 450
using namespace std;
/* A-Z =65-90 a-z=97-122  _=95 */
enum Type{
	none,
	java,
	cpp,
	error
};
void function(string s){
	int i,n=s.length(),ascii;
	Type type=none;
	for(i=0;i<n;i++){
		ascii=(int)s[i];
		if(ascii<=90){
			if(type!=cpp&&i!=0)
				type=java;
			else type=error;
		}
		else if(ascii==95){
			if(i==0||i==(n-1)||s[i+1]=='_'||type==java)
				type=error;
			else type=cpp;
		}
		else;
		if(type==error)
			break;
	}
	if(type==none)
		type=cpp;
	if(type==cpp){
		for(i=0;i<n;i++){
			if(s[i]=='_'){
				i++;
				s[i]=(int)s[i]-32;
				printf("%c",s[i]);
			}
			else printf("%c",s[i]);
		}
		printf("\n");
	}else if(type==java){
		for(i=0;i<n;i++){
			ascii=(int)s[i];
			if(ascii<=90){

				s[i]=(int)s[i]+32;
				printf("_%c",s[i]);
			}
			else printf("%c",s[i]);
		}
		printf("\n");
	}else printf("Error!\n");

}
int main(){
	string s;

	while(cin>>s)
	function(s);
}
