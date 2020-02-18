#include "record.h"
#include<stdlib.h>
#include<stdbool.h>

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);

void MergeSort(Element a[],int s);

// void MergeSort(Element a[],int s);

int min(int a,int b);

void split(Element A[], Element a1[], Element a2[],int s);

long int ispace;
long int fileSize;
int* rspace_1;
int* rspace_2;
long int rspace;
bool r_used;
