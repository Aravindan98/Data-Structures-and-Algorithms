#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

typedef int TaskID;
typedef int Priority;

struct task{
TaskID tid;
Priority p;
};

typedef struct task * Task;

struct Element{
  Task value;
  struct Element* next;
};

typedef struct Element* element;

struct Queue{
  element head;
  element tail;
  Priority p;//can define  priority attribute as well
};

typedef struct Queue* queue;
typedef queue* MultiQ;

queue newQ();

bool isEmpty(queue q);

queue delQ(queue q);

element front(queue q);

queue addQ(queue q,element e);

int lengthQ(queue q);
