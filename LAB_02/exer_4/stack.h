/*********stack.h*******/
#include "linkedlist.h"

struct Stack{
  struct linkedList* head;
};
void push(struct Stack* st,int ele);

struct node* pop(struct Stack* st);

void printStack(struct Stack* st);
