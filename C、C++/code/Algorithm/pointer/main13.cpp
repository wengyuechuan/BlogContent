#include<stdio.h>
#include<stdlib.h>
/**
 * 数组指针数组 => 指针数组 ==>数组
 * 元素是指针，指针是指向数组的指针
 */
int main(void){
    int arr[3]={1,2,3};
    int *arr_1[3];
    arr_1[0]=NULL;
    int num=9;
    arr_1[1]=&num;
    arr_1[2]=arr_1[1];
    printf("arr_1[2] =%x\n",arr_1[2]);//打印出指针变量存储的值 也就是地址
    
    return 0;
}