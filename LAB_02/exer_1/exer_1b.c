#include<stdio.h>
#include<stdlib.h>
void main(int argc, char* argv[]){
	printf("\n");
	//printf("The value for argc is :%d",argc);
	for(int i=0;i<argc;i++){
		if(i==0)
		printf(" %s ",argv[i]+2);
		else
		printf("%s ",argv[i]);
		
	}
		printf("\n");
	
	return;
}
