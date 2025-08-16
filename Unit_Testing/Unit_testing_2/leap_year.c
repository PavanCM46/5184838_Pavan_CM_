#include "demo.h"
#include "unity.h"

int is_leapyear(int yy)
{
   if((yy%400==0)||(yy%4==0 && yy%100!=0))
   return 1;
   else 
   return 0;
}
