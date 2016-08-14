#include <bits/stdc++.h>
using namespace std;

int main()
{
   char c;
   char prev=' ';
   c=getchar();
   while(c!=EOF){
   	
   	if(prev==' '){
   		if(c-'a'>=0 and c-'a'<=25){
   			printf("%c",c-'a'+'A');
   		}
   		else printf("%c",c );
   	}else printf("%c",c);
   	prev=c;
   	c=getchar();
   }
   printf("\n");
}
