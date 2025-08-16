#include "demo.h"
#include "unity.h"

int num_swap(int *a,int *b)
{
  int temp=*a;
    *a=*b;
    *b=temp;
}
