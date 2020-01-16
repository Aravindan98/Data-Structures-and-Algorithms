#include<stdio.h>
#include<stdlib.h>
int main(){
int a=12;
int *address_of_a=&a;
printf("The address of the memory location where variable a gets stored is %x or using &a we get : %x",address_of_a,&a);
printf("\nThe value that gets stored in the memory location is :%d\n",*(address_of_a));
return 0;
}
