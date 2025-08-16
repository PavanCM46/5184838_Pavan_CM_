#include "stdio.h"
#include "demo.h"
#include "unity.h"

void setUp(){
    printf("Before going into test case\n");
    printf("------------------------------\n");
}
void tearDown (){
    printf("After completing the test case\n");
    printf("------------------------------\n");
}
void test_sum(){
    TEST_ASSERT_EQUAL(5,sum(2,3));
    TEST_ASSERT_EQUAL(6,sum(3,3));
}
void test_product(){
    TEST_ASSERT_EQUAL(12,multiply(3,4));
    TEST_ASSERT_EQUAL(16,multiply(2,8));
}



int main(){
    int a=10,b=15,c=0;
    c=sum(a,b);
    printf("The sum of two number is %d\n",c);
    c=multiply(a,b);
    printf("the product of the number is %d\n",c);


    UNITY_BEGIN();
    RUN_TEST(test_sum);
    RUN_TEST(test_product);

    return UNITY_END();
}