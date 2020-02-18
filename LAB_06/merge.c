#include "merge.h"

void split(Element A[], Element a1[], Element a2[],int s)
{
int j1=0,j2=0;
for(int i=0;i<s;i++)
{
  if(i<s/2)
    a1[j1++]=A[i];
  else
    a2[j2++]=A[i];
}
}

void merge(Element a1[], int s1, Element a2[], int s2, Element a[])
{
  int p1=0;
  int p2=0;
  for(int i=0;i<s1+s2;i++)
  if(p1<s1 && p2<s2)
  {
    if(a1[p1].cgpa<a2[p2].cgpa)
    {
      a[i]=a1[p1++];
    }
    else
    {
      a[i]=a2[p2++];
    }
  }
  else if(p1==s1 && p2<s2)
  {
    a[i]=a2[p2++];
  }
  else
  {
    a[i]=a1[p1++];
  }
}
