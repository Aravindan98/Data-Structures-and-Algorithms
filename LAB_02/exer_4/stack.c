#include "stack.h"

void push(struct Stack* st,int ele)
{
	insertFirst(st->head,ele);
}
struct node* pop(struct Stack* st)
{
	return deleteFirst(st->head);
}
void printStack(struct Stack* st)
{
  printList(st->head);
}
