#include "cycle.h"

bool testCyclic(linkedList* Ls)
{
  node* current=(Ls->head);
  node* n=NULL;
  node* prev=NULL;
  //termination is when current=NULL;
  if((Ls->count)==0 || (Ls->head)->next==NULL)
  {
    return false;
  }
  if((Ls->head)->next==(Ls->head))//one element
  {
    return true;
  }
  while(n!=Ls->head)
  {
    // printf("current ele:%d  pointing to:%u\n",current->element,current->next);

    n=current->next;
    if(n==NULL)
      return false;
    current->next=prev;
    prev=current;
    current=n;
  }
return true;
}
