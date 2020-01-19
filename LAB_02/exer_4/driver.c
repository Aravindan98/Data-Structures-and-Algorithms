#include <stdio.h>
#include <stdlib.h>
//#include "linkedlist.h"
#include "stack.h"

int main(int argc, char *argv[])
{
FILE* fptr = fopen(argv[1],"r");

if(fptr==NULL){
  printf("\nFile could not be opened\n");
  exit(1);
}

struct Stack *st=(struct Stack*)malloc(sizeof(struct Stack));
st->head=(struct linkedList*)malloc(sizeof(struct linkedList));

int temp;
while(1)
{
// printf("\n........Scanning....... \t");
fscanf(fptr,"%d",&temp);
if(feof(fptr))
  break;
// printf("%d\n", temp);
push(st,temp);
}
fclose(fptr);
/*
printf("%s\n","list after pushing all elements");
printStack(st->head);
printf("\n");
*/
struct node* t;
while((st->head)->count)
{
  //printf("Stack length:%d",head->count);
  printStack(st);
  t=pop(st);
  printf("element popped! [%d]\n\n",t->element);
  free(t);
}
free(st->head);
return 0;
}
