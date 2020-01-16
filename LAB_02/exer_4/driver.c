#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
//#include "stack.h"

int main(int argc, char *argv[])
{
FILE* fptr = fopen(argv[1],"r");

if(fptr==NULL){
  printf("\nFile could not be opened\n");
  exit(1);
}

struct linkedList *head=(struct linkedList*)malloc(sizeof(struct linkedList));
int temp;
while(1)
{
// printf("\n........Scanning....... \t");
fscanf(fptr,"%d",&temp);
if(feof(fptr))
  break;
// printf("%d\n", temp);
push(head,temp);
}
fclose(fptr);
/*
printf("%s\n","list after pushing all elements");
printStack(head);
printf("\n");
*/
while(head->count)
{
  //printf("Stack length:%d",head->count);
  printStack(head);
  pop(head);
}
/*
if(search(head, 5))
printf("\n\nYes 5 is present in the list\n");
else
printf("\n\nNo 5 is not present in the list\n");

printf(" \n\n\n deleted element : %d\n",delete(head,5)->element);
printList(head);
printf("\n\n");
*/
free(head);
return 0;
}
