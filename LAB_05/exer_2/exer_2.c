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

long long unsigned int last_index=0;
int* bottom;
int* top;

void insertInOrder(Record* r,long long unsigned int index)
{
  // printf("\treached here, index:%d \n",index);
  if(index==0)
  {
		// printf("reached base case\n");
    int b=0;
    top=&b;
    return;
  }
insertInOrder(r,index-1);//sorted till index-1
// printf("\t>>> reached here, index:%d \n",index);


Record key=r[index];

long long int i=index-1;
while((r[i].card_Number>key.card_Number))
{

  r[i+1]=r[i];
  i--;

  	if(i<0)
  		break;

}
r[i+1]=key;
};

void insertionSort(Record* r)
{
	printf("\n\n++++++++BEFORE INSERTION++++++++++++\n\n");
    // for(int i=0;i<last_index+1;i+=100)
		//   printf(" ==> %lld\n",r[i].card_Number);

  insertInOrder(r,last_index);

	printf("\n\n-------POST INSERTION-------------\n");
	 // for(int i=0;i<last_index+1;i+=100)
	 	// printf("==> %lld\n",r[i].card_Number);
};

int main(int argc, char* argv[])
{
	struct timeval t1,t2;
	double elapsedTime;

	long long int size=100;

	FILE* fptr=fopen(argv[1],"r");
  FILE* fout=fopen(argv[2],"a");

	if(fptr==NULL ||fout==NULL)
	{
		printf("%s\n","\nFile opening failed!\n");
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
    // printf("%s %d\n","read",i);
	}
	last_index=i;

  gettimeofday(&t1,NULL);
/////////////////
  int a=0;
  bottom=&a;
  insertionSort(r);
///////////////
  long int stackSize=(long int)(bottom-top);
  gettimeofday(&t2,NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time is  %f ms  stackSize: %ld \n",elapsedTime,stackSize);
  fprintf(fout,"%f,%ld\n",elapsedTime,stackSize);
	fclose(fptr);
  return 0;
}
