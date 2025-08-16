#include "demo.h"
#include "unity.h"

void arr_swap(int arr[], int size) {
    int *st = arr;
    int *ed = arr + size - 1;

    while (st < ed) {
        int temp = *st;
        *st = *ed;
        *ed = temp;

        st++;
        ed--;
    }
}
