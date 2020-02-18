#include "merge.h"

int min(int x, int y) { return (x<y)? x :y; };

void MergeSort(Element A[],int n){
	int mid,r;
	ispace = 2*sizeof(int);
	for(int i_size=1;i_size<n;i_size*=2){
		for(int st=0;st<n;st+=2*i_size){
			int mid = min(st+i_size-1,n-1);
			int r = min(st+2*i_size-1,n-1);

			Element newA[r-st+1];
			ispace += 2*sizeof(int)+(r-st+1)*sizeof(Element);

			merge(A+st,mid-st+1,A+mid+1,r-mid,newA);
			for(int i=0;i<r-st+1;i++){
				A[st+i]=newA[i];
			}
		}
	}
}
