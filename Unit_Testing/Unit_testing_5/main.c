#include "stdio.h"
#include "demo.h"
#include "unity.h"

void setUp(){}
void tearDown(){}

void test_swap(){
    int a=20,b=10;
    num_swap(&a,&b);
    TEST_ASSERT_EQUAL_INT(20,b);
    TEST_ASSERT_EQUAL_INT(10,a);
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_swap);
    return UNITY_END();
}
