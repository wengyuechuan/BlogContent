#include<stdio.h>
#include<stdlib.h>
/**
 * 数组指针：
 * 就是一个指针
 * 指针指向的类型* 指针名
 * 指针指向的类型：数组类型
 * 利用typedef取名
 * 元素类型 (*指针名)[元素个数]
 * typedef 元素类型 (*指针别名)[元素个数]
 */ 
typedef int (*pARR)[3];
typedef int ARR [3]; //长度为3的数组的别名
int main(void){
    int arr[3]={1,2,3};
    ARR arr1={4,5,6};//这样就可以定义了
    //指向了整个的数组
    int (*pArr)[3]=&arr;
    pARR parr1=&arr1;
    //则我们访问数组的前几项有如下的方式
    arr1[0];
    (*parr1)[0];
    parr1[0][0];
    return 0;
}