#include "cycle.h"
#include "alloc_free.h"

void insertFirst(linkedList* Ls, int ele)
{
node* new_node=(node*)myalloc(sizeof(struct node));
new_node->element=ele;
if(Ls->count==0)
{
  new_node->next=NULL;
}
else
{
new_node->next=(Ls->head);
}
Ls->head=new_node;
(Ls->count)++;
}

void deleteFirst(linkedList* Ls){
  if(Ls->count==0)
  {
  printf("\n**No elements present for deletion!**\n");
  return;
  }
  else
  {
    printf("\n......Popping...........");
    struct node* temp=Ls->head;
    Ls->head=temp->next;
    myfree(temp);
    (Ls->count)--;
    printf("Done!\n");
    return;
  }
}

linkedList* createList(int N)
{
  linkedList* Ls=(linkedList*)myalloc(sizeof(linkedList));
  for(int i=0;i<N;i++)
  {
    int a=rand()%10;
    insertFirst(Ls,a);
    // printf("%d inserted in Ls and the head is %d \n",a,(Ls->head)->element);
  }
  return Ls;
}

linkedList* createCycle(linkedList* Ls)
{
  // printf("\nInside create cycle!\n");
  int coin_toss=rand()%2;
  printf("coin_toss=%d\n",coin_toss);
  if(coin_toss==0)
  {
    printf("\n#### COIN_TOSS_RESULT: Cyclic ####\n");
    //chosen to be cyclic
    int r=(rand()%(Ls->count));
    // printf("\tvalue of r:%d\n",r);
    struct node* pointer;
    struct node* tail=Ls->head;
    int c=0;
    while(tail->next!=NULL)
    {
      // printf("current tail pos%d value in next element %d and c:%d r:%d \n",tail->element,(tail->next)->element,c,r);
      if(c==r)
      {
        // printf("\nreached position r\n");
        //have reached the node r;
        pointer=tail;
      }
      tail=tail->next;
      c++;
    }
    // printf("\ntail->next==NULL %u\n",tail->next);
    // printf("current tail pos %d value in next element %d and c:%d r:%d \n",tail->element,(tail->next),c,r);
    tail->next=pointer;
    // printf("current tail pos %d pointing to %u where value is %d\n",tail->element,(tail->next),(tail->next)->element,r);
    return Ls;
  }
  else
  {
    printf("\n#### COIN_TOSS_RESULT: Linear ####\n");
    return Ls;
  }
}
