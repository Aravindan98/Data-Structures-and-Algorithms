/***********file:   Ops.c *********/
#include <stdio.h>
#include "storage.h"
#include "compare.h"
#include <stdbool.h>

int nextfreeloc = 0;
Store st;
bool flag[3]={0,0,0};

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return sl;
}

void printJob(Job j)
{
printf ("JOB ID = %d, Priority = %d, Execution Time = %d, Arrival Time = %d \n",j.id,j.pri,j.et,j.at);
}

//works!
int inputJobs(JobList list)
{
 int i; int size;
 int p;
 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&p);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
  list[i].pri=p;
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{

if(sl.size==0)
{
st[sl.head].ele=j;
}
else if(compare(j,st[sl.head].ele)==LESSER)
{
  int i=nextfreeloc++;
  st[i].ele=j;
  st[i].next=sl.head;
  sl.head=i;
}
else
{
  int i=nextfreeloc++;
  st[i].ele=j;
  st[i].next=-1;
  int prev=sl.head;
  int pointer=st[sl.head].next;

  while(pointer!=-1)
  {
  if(compare(j,st[pointer].ele)==GREATER)
  {
    prev=pointer;
    pointer=st[pointer].next;
  }
  else
  break;
  }
  st[prev].next=i;
  st[i].next=pointer;
}
sl.size++;
return sl;
}

void insertelements (JobList list , int size, SeqList seq[3])
{
for(int j=0;j<3;j++)
{
for(int i=0;i<size;i++)
{
  if((int)list[i].pri==j)
  {
    if(flag[j]==1)
	   {
       seq[j]=insert(list[i],seq[j]);
     }
     else
     {
       seq[j]=createlist();
       seq[j]=insert(list[i],seq[j]);
       flag[j]=1;
     }
   }
 }
}

}

void copy_sorted_ele(SeqList s[3] , JobList list)
{
  int i=0;
  for(int j=2;j>=0;j--)
  {
  if(flag[j]==0)
  {
    continue;
  }
  int pointer=s[j].head;
  while(pointer !=-1)
  {
    list[i]=st[pointer].ele;
    pointer=st[pointer].next;
    i++;
  }
}

}

void printlist(SeqList sl)
{
  if(sl.size==0) return;
  int i=0;
  int pointer=sl.head;
  while(pointer !=-1)//could possible add size constraint
  {
    printJob(st[pointer].ele);
    pointer=st[pointer].next;
    i++;
  }

}

//correct code
void printJobList(JobList list, int size)
{
for(int i=0;i<size;i++)
{
    printJob(list[i]);
}
}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 //seq[0] = createlist();
 //seq[1] = createlist();
 //seq[2] = createlist();
 insertelements (list, size, seq);

 printf("\n::::::: BUCKET with PRIORITY 0 :::::::::\n");

 if(flag[0]==0)
 printf("%s\n","-------------- EMPTY----------------" );
 else
 printlist(seq[0]);

 printf("\n\n::::::: BUCKET with PRIORITY 1 :::::::::\n");
 if(flag[1]==0)
 printf("%s\n","-------------- EMPTY----------------" );
 else
 printlist(seq[1]);


 printf("\n\n::::::: BUCKET with PRIORITY 2 :::::::::\n");
 if(flag[2]==0)
 printf("%s\n","-------------- EMPTY----------------" );
 else
 printlist(seq[2]);

 copy_sorted_ele (seq , list);
}
