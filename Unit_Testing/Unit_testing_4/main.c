#include "stdio.h"
#include "unity.h"
#include "demo.h"

void setUp(){}
void tearDown(){}

void test_avg(){
    int arr[]={1,2,3,4,5};
    TEST_ASSERT_FLOAT_WITHIN(0.0,3.0,arr_average(arr,5));
    TEST_ASSERT_FLOAT_WITHIN(0.21,2.8,arr_average(arr,5));
    TEST_ASSERT_FLOAT_WITHIN(0.5,2.5,arr_average(arr,5));
    TEST_ASSERT_FLOAT_WITHIN(0.0,0.0,arr_average(arr,0));

}
int main(){
    UNITY_BEGIN();
    RUN_TEST(test_avg);
    UNITY_END();
}