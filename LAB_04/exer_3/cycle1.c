/*
Hare-and-Tortoise algorithm:
Maintain two pointers hare and tort such that hare jumps two nodes in the linked
list when tort jumps one node. Repeat the jumps in loc-step until hare finds itself
behind tort or in step with tort. Ensure that trivial/special cases are handled
properly: empty list, singleton list, a list with two nodes, and a linear list (i.e. one that
terminates.)
*/

#include "cycle.h"

bool testCyclic(linkedList* Ls)
{

  bool is_cyclic=false;

  if(Ls->count==0)
{
  return is_cyclic;
}
  node* tort=Ls->head;
  node* hare=Ls->head;

  if(Ls->count==1)
  {
    if(tort->next!=NULL)
      is_cyclic=true;
      return is_cyclic;
  }
  else if(Ls->count==2)
  {
    if((tort->next)->next!=NULL)
      is_cyclic=true;
      return is_cyclic;
  }
  else
  {
    int c=1;
    while(1)
    {
    // printf("\n -------hare:%u ------- tort %u \n",hare,tort);
    // printf("\t%d---",c);
    hare=(hare->next)->next;
    tort=tort->next;
    // printf("-----^^^ hare:%u -------^^^^ tort %u \n",hare,tort);
    c++;
    if(hare==NULL || hare->next==NULL)
    {
      printf("\nlinear\n");
      break;
    }

    if(hare==tort)
    {
      is_cyclic=true;
      printf("\ncyclic\n");
      break;//cycle condition
    }
  }
  }
  return is_cyclic;
}
