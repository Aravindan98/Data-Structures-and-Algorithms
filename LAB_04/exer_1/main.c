#include<stdio.h>
int BITS=0;
int pop(int p);
int pop(int p)
{
  if(BITS==50)
  return 0;
  printf("\nINSIDE P----Address of p %u-------value of p: %d",&p,BITS);
  BITS+=1;
    return pop(BITS);
}
void g(void)
{
  int goa=3;
  printf("\nINSIDE G----Address of goa %u",&goa);
};

int main(void)
{
  printf("\nAddress of global variable BITS %u\n",&BITS);
  pop(BITS);
  // g();
  return 0;
}
