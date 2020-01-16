#include "stack.h"

void push(struct linkedList *head,int ele)
{
	insertFirst(head,ele);
}
void pop(struct linkedList *head)
{
	deleteFirst(head);
}
void printStack(struct linkedList *head)
{
  printList(head);
}
