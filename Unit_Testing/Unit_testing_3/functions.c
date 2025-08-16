#include "demo.h"
#include "unity.h"
#include <stdbool.h>

bool is_even(int a){
    return a%2==0;
}

int is_max(int a, int b)
{
    return (a>b)?a:b ;
}

int is_min(int a, int b)
{
    return (a<b)?a:b ;
}