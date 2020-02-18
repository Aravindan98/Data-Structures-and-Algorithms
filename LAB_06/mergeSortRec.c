#include "merge.h"

void MergeSort(Element a[],int s)
{
  if(s==1)
  {
    int a;
    rspace_2=&a;
    return;
  }
  // if(s==fileSize)
  // {
  //   int a;
  //   rspace_1=&a;
  // }
  Element* a1=(Element*)calloc(sizeof(Element),s/2);
  Element* a2=(Element*)calloc(sizeof(Element),s-(s/2));
  split(a,a1,a2,s);
  MergeSort(a1,s/2);//a1 is a sorted subarray
  MergeSort(a2,s-(s/2));//a2 is a sorted subarray
  merge(a1,s/2,a2,s-(s/2),a);
  free(a1);
  free(a2);
  r_used=1;
}
