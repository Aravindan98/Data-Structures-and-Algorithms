/*
myalloc invokes malloc to allocate the space as requested and returns the
starting address of the allocated block; in addition, myalloc updates a global
variable that keeps track of total space allocated in the heap so far.

myfree invokes free to free the space pointed to by the given argument, and
in addition, updates the global variable that keeps track of total space
allocated in the heap.
(b) Write a loop that repeatedly allocates and frees a dynamic array of size M using your
myalloc and myfree procedures. In each iteration:
i. choose a random number M in the range 10,000 to 25,000.
ii. allocate an array A of M integers. Use sizeof to make it portable.
iii. print the addresses of the first and the last location of A i.e. A and &(A[M-1])
iv. free A
The loop should terminate when allocation fails. Test the return value of malloc for
failure.
(c) Summarize your understanding (for yourself) of heap space used.
*/
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
long int total_space_allocated=0;
int total_no_elements=0;

void* myalloc(int space_size){
  total_no_elements=space_size/4;
  total_space_allocated+=space_size;
return malloc(space_size);
};

void myfree(void* p){
  p=(int*)p;
  for(int i=0;i<total_no_elements;i++)
  {
  total_space_allocated-=4;
  }
  free(p);
  return;
};

int main()
{
  srand(time(0));
for(int i=0;i<5;i++)
{
int a=10000+(rand()%15001);
printf("\nRand no is :%d\n",a);
int* b=(int*)myalloc(sizeof(int)*a);
printf("***** *** address of first loc:%u and last loc:%u diff:%d *** *****",&b[0],&b[4*(a-1)],&b[4*(a-1)]-&b[0]);
printf("\n total_space_alloted: %d\n",total_space_allocated );
myfree(b);
printf("\n total_space_alloted: %d\n",total_space_allocated );
}
return 0;
}
