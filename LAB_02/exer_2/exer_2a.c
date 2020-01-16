/*
Write a C program that copies the contents of a file into a different file (given two filenames
as command line arguments). Take any two sample files and do them. Error-proof your argument: i.e.
detect and print messages when errors occur – for instance, file is not present, unable to read/write, etc.
Also ensure that your program terminates gracefully when errors occur.
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *file_source=NULL,*file_destination=NULL;
	file_source=fopen("source.txt","r");
	file_destination=fopen("destination.txt","w");
	if(file_source==NULL || file_destination==NULL)
	{
		printf("\n***** ERROR IN OPENING File\n");
		exit(1);
	}
	while(1){
		char ch=fgetc(file_source);
		fputc(ch,file_destination);
		if(ch==EOF) break;
	}
	fclose(file_source);
	fclose(file_destination);
	return 0;
}
