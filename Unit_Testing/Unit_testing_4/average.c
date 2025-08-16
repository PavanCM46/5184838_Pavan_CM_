#include "demo.h"
#include "unity.h"

float arr_average(int arr[],int size){
    float sum=0;
    if(arr==NULL||size==0) return 0;
    else{
        for(int i=0;i<size;i++)
        {
            sum+=arr[i];
        }
    }
    return (float)sum/size;
}