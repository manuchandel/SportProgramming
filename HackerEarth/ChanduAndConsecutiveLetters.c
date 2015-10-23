#include <stdio.h>

int main()
{
	int T;
	int i,n;
	char string[31];
	scanf("%d",&T);
	while(T--){
		scanf("%s",string);
		n=strlen(string);
		printf("%c",string[0]);
		for(i=1;i<n;i++){
			if(string[i]!=string[i-1])
				printf("%c",string[i]);
		}
		printf("\n");
	}
    return 0;
}

