/***********file:   main.c *********/
#include <stdio.h>
#include "seqListOps.h"

int main(void)
{
 int size;
 JobList list;
 size = inputJobs(list);
 printf("\n\n           ***************** The Jobs waiting on CPU ******************      \n\n");
 printJobList(list, size);
 sortJobList(list, size);
 printf("\n\n              *************** POST SORTING **************** \n");
 printJobList(list, size);
 return 0;
}
