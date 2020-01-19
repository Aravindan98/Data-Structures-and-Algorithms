#include "linkedlist.h"
#include<stdlib.h>
#include<stdio.h>

void insertFirst(struct linkedList *head, int ele)
{
struct node *new_node=(struct node*)malloc(sizeof(struct node));
new_node->element=ele;
if(head->count==0)
{
  new_node->next=NULL;
}
else
{
new_node->next=head->first;
}
head->first=new_node;
(head->count)++;
}

struct node* deleteFirst(struct linkedList *head){
  if(head->count==0)
  {
  printf("\n**No elements present for deletion!**\n");
  return NULL;
  }
  else
  {
    printf("\n......Popping...........");
    struct node* temp=head->first;
    //free(head->first);
    head->first=temp->next;
    (head->count)--;
    printf("Done!\n");
    return temp;
  }
}

void printList(struct linkedList *head){
  struct node *i=head->first;
  //printf("|%d| and i->next= %x  ",i->element,i->next);
  printf("\tPrinting\n");
  while(i!=NULL)
  {
    printf("  [%d]  ",i->element);
    i=i->next;
  }
  printf("\n");
}

int search(struct linkedList *head, int ele){
  struct node* i=head->first;
  while(i!=NULL){
    printf(". " );
    if(i->element==ele){
    printf("\n******   %s   ********\n"," Element found!");
    return 1;
    }
  i=i->next;
  }
  printf("\n Element not found\n" );
  return 0;
}

struct node* delete (struct linkedList * head, int ele){
  struct node* i=head->first;
  struct node* temp;
  if((head->first)->element==ele)
  {
    return deleteFirst(head);
  }
  while(i!=NULL){
    if((i->next)->element==ele){
      //temp->element=ele;
      //temp->next=(i->next)->next;
      temp=i->next;
      //free(i->next);
      i->next=temp->next;
      printf("******   %s   ********\n"," Element found!");
      (head->count)--;
      return temp;
    }
  i=i->next;
  }
  printf("............Element not found\n" );
  return NULL;
}
