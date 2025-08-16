#include "demo.h"
#include "stdio.h"
#include "unity.h"

void setUp(){}
void tearDown(){}

void test_leap(){
    TEST_ASSERT_EQUAL(1,is_leapyear(2000));
    TEST_ASSERT_EQUAL(1,is_leapyear(1997));
    }
void test_nonleap(){
  TEST_ASSERT_NOT_EQUAL(1,is_leapyear(1999));
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_leap);
    RUN_TEST(test_nonleap);
    return UNITY_END();

    
}