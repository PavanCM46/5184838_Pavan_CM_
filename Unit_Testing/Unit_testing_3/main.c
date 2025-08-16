#include "stdio.h"
#include "demo.h"
#include "unity.h"
#include <stdbool.h>

void setUp(){}
void tearDown(){}

void test_even()
{
    TEST_ASSERT_EQUAL(1,is_even(4));
    TEST_ASSERT_EQUAL(1,is_even(100));
    TEST_ASSERT_TRUE(is_even(18));
}
void test_noteven()
{
    TEST_ASSERT_NOT_EQUAL(1,is_even(11));
    TEST_ASSERT_NOT_EQUAL(1,is_even(71));
    TEST_ASSERT_FALSE(is_even(5));
}

void test_max(){
    TEST_ASSERT_EQUAL(30,is_max(20,30));
    TEST_ASSERT_EQUAL_INT(30,is_max(30,10));
    TEST_ASSERT_GREATER_THAN(30, is_max(50,20));
    TEST_ASSERT_GREATER_OR_EQUAL(10,is_max(10,5));

}
void test_min(){
    TEST_IGNORE();
    TEST_ASSERT_EQUAL(3,is_min(10,3));
    TEST_ASSERT_EQUAL_INT(5,is_min(10,5));
    TEST_ASSERT_LESS_THAN(3,is_min(2,1));
    TEST_ASSERT_LESS_OR_EQUAL(5,is_min(5,10));

}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_even);
    RUN_TEST(test_noteven);
    RUN_TEST(test_max);
    RUN_TEST(test_min);
    return UNITY_END();
}