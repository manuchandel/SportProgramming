#include <stdio.h>

int main()
{
	int T;
	int i;
	char string[31];
	scanf("%d",&T);
	while(T--){
		scanf("%s",string);
		for(i=strlen(string)-1;i>=0;i--)
			 printf("%c",string[i]);
		printf("\n");
	}
    return 0;
}
