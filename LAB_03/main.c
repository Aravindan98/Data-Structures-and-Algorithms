#include<stdio.h>
#include "que.h"

int main(void){
queue q=newQ();

printf("\nlength of Queue :%d Queue head: %x  and tail:%x  \n",lengthQ(q),q->head,q->tail);

element e=(struct Element*)malloc(sizeof(struct Element));
e->value=5;

q=addQ(q,e);

printf("\nlength of Queue :%d Queue head: %x  and tail:%x  \n",lengthQ(q),q->head,q->tail);

printf("\nThe value : %d\n",(q->tail)->value);

element e_1=(struct Element*)malloc(sizeof(struct Element));
q=addQ(q,e_1);
e_1->value=10;

printf("\nlength of Queue :%d Queue head: %x  and tail:%x  \n",lengthQ(q),q->head,q->tail);

q=delQ(q);

printf("\nlength of Queue :%d Queue head: %x  and tail:%x  \n",lengthQ(q),q->head,q->tail);

q=delQ(q);

printf("\nlength of Queue :%d Queue head: %x  and tail:%x  \n",lengthQ(q),q->head,q->tail);


// printf("\nlength of Queue :%d\n",lengthQ(q));

//free(e);
return 0;
}
