#include "que.h"

queue newQ(queue q)
{
//returns an empty Queue
q=(queue)malloc(sizeof(struct Queue));
// printf("%s\n","inside NewQ");
q->head=NULL;
q->tail=NULL;
q->p=-1;
return q;
}

bool isEmpty(queue q)
{
// test whether the queue is empty or not
if(q->head==NULL && q->tail==NULL)
return true;

return false;
}

queue delQ(queue q)
{
// deletes the element from the front of the Queue
if(!isEmpty(q))
{
if(lengthQ(q)==1)
  {
    // printf("%s\n","length = 1...setting tail=null and p=-1" );
    q->tail=NULL;
    q->p=-1;
  }
element temp=(q->head)->next;
free(q->head);
q->head=temp;
}
return q;
}

element front(queue q)
{
// returns the element from the front of the queue
return(q->head);
}

queue addQ(queue q,element e)
{
// adds element to the rear of the Queue; returns the modified Queue
if(isEmpty(q))
{
q->head=e;
q->p=(e->value)->p;
}
else
{
(q->tail)->next=e;//link established in the chain
}

q->tail=e;
e->next=NULL;

return q;
}

int lengthQ(queue q)
{
	//returns length of the Queue
int Queue_length=0;

element pointer=q->head;

while(pointer != NULL){
Queue_length++;
pointer=(pointer)->next;
}

return Queue_length;
}
