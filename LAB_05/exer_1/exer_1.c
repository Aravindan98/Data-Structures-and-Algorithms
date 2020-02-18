#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>

typedef struct Record{
long long int card_Number;
char* Bank_Code[5];
char* Exp_Date[7];
char* FirstName[5];
char* LastName[5];
}Record;

int main(int argc, char* argv[])
{
	struct timeval t1,t2;
	double elapsedTime;

	long long int size=100;

	FILE* fptr=fopen(argv[1],"r");
	if(fptr==NULL)
	{
		printf("%s\n","\nFile reading failed!\n");
		exit(1);
	}

	Record* r=(Record*)calloc(size,sizeof(Record));
	char rec[100];
	char bc[10];
	char ex[10];
	char fn[10];
	char ln[10];
	char gar[3];

	long long int i=0;
	while(1)
	{
		if(i==size)
		{
			size+=10;
			r=(Record*)realloc(r,size*sizeof(Record));
		}

		fscanf(fptr,"%[\"]%[^,],%[^,],%[^,],%[^,],%[^\"]%[\"]\n",gar,rec,bc,ex,fn,ln,gar);
		r[i].card_Number=atoll(rec);
		strncpy(r[i].Bank_Code,bc,6);
		strncpy(r[i].Exp_Date,ex,7);
		strncpy(r[i].FirstName,fn,5);
		strncpy(r[i].LastName,ln,5);

		if(feof(fptr))
			break;
		i++;
    printf("%s %d\n","read",i);
	}


	fclose(fptr);
  return 0;
}
