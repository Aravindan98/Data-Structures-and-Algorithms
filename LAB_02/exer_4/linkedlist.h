struct node{
int element;
struct node *next;// next is a pointer variable to a node structure
};

struct linkedList{
int count;
struct node *first;
};

void insertFirst(struct linkedList *head, int ele);

void deleteFirst(struct linkedList *head);

void printList(struct linkedList *head);

int search(struct linkedList *head, int ele);

struct node* delete (struct linkedList * head, int ele);

/*
void push(struct linkedList* head,int ele);
void pop(struct linkedList* head);
*/
