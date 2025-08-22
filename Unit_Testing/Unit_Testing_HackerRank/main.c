#include "stdio.h"
#include "demo.h"
#include "unity.h"

void setUp(){}
void tearDown(){}

void test_superDigit(){
  TEST_ASSERT_EQUAL_INT(1,superDigit("1",1)); 
  TEST_ASSERT_EQUAL_INT(3,superDigit("148",3)); 
  TEST_ASSERT_EQUAL_INT(8,superDigit("9875",4)); 
}

void test_not_superDigit(){
  TEST_ASSERT_NOT_EQUAL_INT(10,superDigit("1",1)); 
  TEST_ASSERT_NOT_EQUAL_INT(30,superDigit("148",3)); 
  TEST_ASSERT_NOT_EQUAL_INT(80,superDigit("9875",4)); 
}


int main(){
    UNITY_BEGIN();
    RUN_TEST(test_superDigit);
    RUN_TEST(test_not_superDigit);
    return UNITY_END();
}
