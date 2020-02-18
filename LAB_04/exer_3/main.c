#include "cycle.h"
#include <sys/time.h>
#include<time.h>

long int total_space_allocated=0;

void* myalloc(int space_size){
total_space_allocated+=space_size;
// printf("\n\t========HEAP SPACE %ld =======\n",total_space_allocated);
return malloc(space_size);
};

void myfree(void* p){
  p=(int*)p;
  total_space_allocated-=sizeof(*p);
  // printf("\n\t========HEAP SPACE %ld =======\n",total_space_allocated);
  free(p);
  return;
};

int main(int argc,char* argv[])
{
  FILE* f=fopen("OUTPUT_linkreversal.csv","a");
  srand(time(0));
  struct timeval t1,t2;
  double elapsedTime;

  linkedList* Ls=createList(atoi(argv[1]));
  Ls=createCycle(Ls);

  printf("************ total_space_allocated:%ld **************\n",total_space_allocated);
  gettimeofday(&t1,NULL);
  if(testCyclic(Ls))
  {
    printf("\n          ++++++++ LIST is CYCLIC +++++++++\n");
  }
  else
  {
    printf("\n          ++++++++ LIST is Linear +++++++++\n");
  }
  gettimeofday(&t2,NULL);
  elapsedTime=(t2.tv_sec-t1.tv_sec)*1000.0;
  elapsedTime+=(t2.tv_usec-t1.tv_usec)/1000.0;
  printf("\nTotal time elasped :%f ms.\n",elapsedTime);
  fprintf(f,"\n%d,%ld,%f",atoi(argv[1]),total_space_allocated,elapsedTime);
  fclose(f);
  return 0;
}
