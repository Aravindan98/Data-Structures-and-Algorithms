#include<stdlib.h>
#include "alloc_free.h"

total_space_allocated=0;

void* myalloc(int space_size){
total_space_allocated+=space_size;
printf("\n\t========HEAP SPACE %ld =======\n",total_space_allocated);
return malloc(space_size);
}

void myfree(void* p){
  p=(int*)p;
  total_space_allocated-=sizeof(*p);
  printf("\n\t========HEAP SPACE %ld =======\n",total_space_allocated);
  free(p);
  return;
}
