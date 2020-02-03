/*Write a procedure createList(N) that generates N random numbers and stores them
in a linear linked list Ls and returns Ls. All the allocation in this procedure must use
myalloc. Output the total heap space allocated to a text file. N must be large (say 1
million or more.)
*/

#include<linkedlist.h>
linkedList* createList(int N)
{
  linkedList* Ls=(linkedList*)myalloc(sizeof(linkedList));
  //inserting
  for(int i=0;i<N;i++)
  {
    int a=rand();
    insertFirst(Ls,a);
  }
  return Ls;
}

/*
Write a procedure createCycle(Ls) that tosses a coin – programmatically – to decide
whether Ls must be linear or cyclic. If it must be cyclic, this procedure picks a random
number, say r, and lets the last node in Ls point to (i.e. set its next to point to) the
node containing r. If it must be linear this procedure returns Ls as is.
(c) Write a main program that creates a new linked list Ls using the createList and
createCycle procedures. Note that such a list Ls may or may not be cyclic. The main
program should classify Ls as linear or cyclic by invoking a procedure testCyclic that is
declared in a header file cycle.h. Test the program with a dummy implementation of
testCyclic that returns FALSE always (or TRUE always)
*/
#include "linkedlist.h"

createCycle(linkedList* Ls)
{
  int coin_toss=rand()%2;
  if(coin_toss==0)
  {
    //chosen to be cyclic
    int r=(rand()%N)+1;
    struct node* pointer;
    struct node* tail=Ls->head;
    int c=1;
    while(tail->next!=NULL)
    {
      if(c==r)
      {
        //have reached the node r;
        pointer=tail;
      }
      tail=tail->next;
      c++;
    }
    tail->next=pointer;
    //cycle done!
    return Ls;
  }
  else
  {
    return Ls;
  }
}
