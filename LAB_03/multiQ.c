// **********multiQ.h ***********
// #include "que.h"
#include "multiQ.h"
// #include <stdlib.h>
// #include <stdbool.h>

int total_queues=0;
int max_size;

MultiQ createMQ(int num) // creates a list of num Queues, each of which is empty.createMQ should dynamically allocate an array of size num (the value that is passed to it) and return it
{
MultiQ mq;
// for(int i=0;i<num;i++)
// {
//   (mq+sizeof(Queue))=newQ();
// }//q has the base address of the array of Queues //
//iterate through the que array calling newQ
max_size=num;
mq=(queue *)calloc(num,sizeof(queue));
for(int i=0;i<num;i++)
{
  mq[i]=newQ(mq[i]);
}
// printf("%s\n","inside multiQ");

return mq;
}

MultiQ addMQ(MultiQ mq, Task t) // adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p.
{
//go to the Queue with the respective priority and call addQ.
// if out of space then error
element e=(struct Element*)malloc(sizeof(struct Element));
e->value=t;
int i;
bool alloted=false;
for(i=0;i<total_queues;i++)
{
if(mq[i]->p==t->p)
  {
    mq[i]=addQ(mq[i],e);
    alloted=true;
  }
}

if(total_queues<=max_size)
{
  if(alloted==false)
  {
  total_queues++;
  mq[i]=addQ(mq[i],e);//initalize
  }
}
else
{
printf("\n......not enough space alloted.....TASK not added \n");
return NULL;
}
return mq;
}

Task nextMQ(MultiQ mq) // returns the front of the non-empty Queue in mq with the highest priority.
{
//check for the queue with the highest priority and then call front. In case empty then
if(isEmptyMQ(mq))
  return NULL;

int max_prior_index=0;
for(int i=1;i<total_queues;i++)
{
  if(mq[i]->p>mq[max_prior_index]->p)
    max_prior_index=i;
}
return front(mq[max_prior_index])->value;
}

MultiQ delNextMQ(MultiQ mq) // deletes the front of the non-empty Queue in mq with the highest priority; returns the modified MultiQ
{
//check for the queue with the highest priority and then call delQ. In case empty then
if(isEmptyMQ(mq))
  return NULL;

int max_prior_index=0;
for(int i=1;i<total_queues;i++)
{
  // printf("max_prior_index: %d\n",max_prior_index);
  // printf("mq[max_prior_index]=%d   mq[%d]=%d \n",mq[max_prior_index]->p,i,mq[i]->p);
  if(mq[i]->p == -1)
    continue;
  if((mq[i]->p)>(mq[max_prior_index]->p))
    max_prior_index=i;
}
// if(lengthQ(mq[max_prior_index])>1)
  mq[max_prior_index]=delQ(mq[max_prior_index]);

return mq;
}

bool isEmptyMQ(MultiQ mq) // tests whether all the Queues in mq are empty
{
// just check if all queues in the array are empty using isEmpty.
for(int i=0;i<total_queues;i++)
{
  if(!isEmpty(mq[i]))
    return false;
}
return true;
}

int sizeMQ(MultiQ mq)
{
  printf("total_queues: %d\n",total_queues);
  int total_item_count=0;
  for(int i=0;i<total_queues;i++)
  {
    total_item_count+=lengthQ(mq[i]);
  }
  return total_item_count;
}

int sizeMQbyPriority(MultiQ mq, Priority p)// returns the number of items in mq with the priority p.
{
return lengthQ(getQueueFromMQ(mq,p));
}

queue getQueueFromMQ(MultiQ mq, Priority p)// returns the Queue with priority p.
{
// check priority and return Queue

int i=0;
while(1)
{
  printf("%s  %d\n","################ reached here #############",i );
  if(mq[i]->p==p && i<total_queues)
    {
      printf("%s\n","################ Priority Matched! #############" );  
      return mq[i];
      break;
    }
else
  i++;
}
}
