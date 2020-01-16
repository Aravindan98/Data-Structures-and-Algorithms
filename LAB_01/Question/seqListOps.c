/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Exe time = %d \n",j.id,j.pri,j.et,j.at);
}

int inputJobs(JobList list)
{
 int i; int size;
 int x;
 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&x);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
  list[i].pri=x;
 }
 //printf("Inside inputJob: %d\n",size);
 return size;
}

SeqList insert(Job j , SeqList sl)
{
  if(sl.size==0) {
   st[sl.head].ele=j;
   st[sl.head].next=nextfreeloc++;
  }
  else if(compare(st[sl.head].ele,j) == GREATER) {
   st[nextfreeloc].ele=j;
   st[nextfreeloc].next=sl.head;
   sl.head=nextfreeloc++;
  }
  else {
   int i,k;
   for(i=sl.head,k=0;compare(st[st[i].next].ele,j) != GREATER && k<sl.size;i=st[i].next,k++);
   if(k!=sl.size) {
    st[nextfreeloc].ele=j;
    st[nextfreeloc].next=st[i].next;
    st[i].next=nextfreeloc++;
   }else {
    st[i].ele=j;
    st[i].next=nextfreeloc++;
   }
  }
  sl.size++;
  return sl;
}

void insertelements (JobList list , int size, SeqList s[3])
{
/*
for(int i=0;i<3;i++)
{
  s[i]=createlist();
  //printf("%d",s[i].size);
  for(int j=0;j<size;j++){
    if(list[j].pri==i)
    {
      insert(list[j],s[i]);
    }
  }
  printlist(s[i]);
}
*/
for(int t=0;t<3;t++)
{
  for(int i=0;i<size;i++)
{
  if((int)list[i].pri==t)
  s[(int)list[i].pri]=insert(list[i],s[(int)list[i].pri]);
}
}
}
void copy_sorted_ele(SeqList s[3] , JobList ele)
{
/*This function copies all the Jobs in three SeqLists (of seqarr) back into ele. Copying is to be done priority
wise, ie copy the Jobs with Priority 2 first into ele, then jobs with Priority 1 and then jobs with Priority
0. Now, joblist consists of Jobs sorted in order of highest Priority and lowest arrival time OR highest
Priority and lowest execution time.
*/
/*
int i,j;
int index = 0;
printf ("\n \n");
for (i=2 ; i>=0 ; i--)
{
 for (j=st[s[i].head].next ; st[j].next != -1; j = st[j].next)
 {
  ele[index] = st[j].ele;
  index++;
 }
 ele[index] = st[j].ele;
 index++;
}*/
int i=0;
 for(int j=2;j>-1;j--){
  int temp=s[j].head;
  for(int k=0;k<s[j].size;temp=st[temp].next,k++){
   ele[i++]=st[temp].ele;
  }
 }
}

void printlist(SeqList sl)
{
 for(int i=0, temp=sl.head; i<sl.size; i++, temp=st[temp].next) printJob(st[temp].ele);
 printf("\n");
}

void printJobList(JobList list, int size)
{
 for(int i=0;i<size;i++) printJob(list[i]); printf("\n");
}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);
 printlist(seq[0]);
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list);
}
