#include<stdio.h>
#include<stdlib.h>
void main(int argc, char* argv[]){
	printf("\n");
	//printf("The value for argc is :%d",argc);
	for(int i=1;i<argc;i++)
	{
		if(argv[i]!="0" && atoi(argv[i])==0)
		printf("%s",argv[i]);
		else
		printf("%d ",atoi(argv[i])+1000);
	}
	printf("\n");
	return;
}
