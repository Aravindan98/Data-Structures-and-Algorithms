#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
int element;
struct node *next;// next is a pointer variable to a node structure
}node;

typedef struct linkedList{
int count;
node* head;
}linkedList;

extern void insertFirst(linkedList* Ls, int ele);
extern linkedList* createList(int N);
extern linkedList* createCycle(linkedList* Ls);
extern void deleteFirst(linkedList* Ls);
extern linkedList* makeCircularList(linkedList* Ls);
