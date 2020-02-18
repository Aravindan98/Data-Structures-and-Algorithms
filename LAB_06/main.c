#include <stdio.h>
#include "merge.h"
#include <time.h>
#include <sys/time.h>

int main(int argc,char* argv[])
{
FILE* fptr=fopen(argv[1],"r");
FILE* out_ptr=fopen("output.txt","a");
fileSize=atol(argv[2]);

struct timeval t1, t2;
double elapsedTime=0;
long long int space_used=0;

printf("\n====== Opened: %s ======\n",argv[1]);
rec r[fileSize];
if(fptr==NULL || out_ptr==NULL)
{
  printf("\n>>>>>>>> ERROR OPENING FILE <<<<<<<<<<(use command line i/p for filename)\n");
  exit(1);
}
int i=0;
while(1)
{
  char data[10+1+3];
  fscanf(fptr,"%[^,],%f\n",r[i].name,&(r[i].cgpa));
  // printf("\n%s--%f",r[i].name,r[i].cgpa);
  if(feof(fptr))
  {
    break;
  }
  i++;
}

  printf("\n");
  gettimeofday(&t1, NULL);
  int a;
  rspace_1=&a;
  MergeSort(r,fileSize);
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  if(r_used==1)
  {
    rspace=rspace_1-rspace_2;
    fprintf(out_ptr,">>>>> RECURSION USED <<<<< \nfileSize:%d ::: elapsedTime ::: %f space_used:%ld\n",fileSize,elapsedTime,rspace);
  }
  else
  {
  fprintf(out_ptr,">>>>> ITERATION USED <<<<< \nfileSize:%d ::: elapsedTime ::: %f space_used:%ld\n",fileSize,elapsedTime,ispace);
  }
  // for(int i=0;i<fileSize;i+=100)
  // {
  //   printf("r[%d]: (%s,%f) \n",i,r[i].name,r[i].cgpa);
  // }

  // gettimeofday(&t1, NULL);
  // MergeSort(r,fileSize);
  // gettimeofday(&t2, NULL);
  // elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
  // elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  // fprintf("fileSize:%d ::: elapsedTime ::: %d ::: space_used:%d\n",fileSize,elapsedTime,space_used);
}
