#include<stdio.h>
#include<stdlib.h>
int main(){
    void* p_0=NULL;
    p_0=(void*)0x1234;
    printf("p_0:%x",p_0);
    // p_0++;  这里会发现void*的指针不能自增 同样的这个指针不能进行运算
    int num=10;
    int *p_1=NULL;
    p_1=&num;
    int *p_2=(int*)0Xcd00;
    p_0=p_1; //这里可以进行赋值
    printf("p_2:%x",p_2);
    p_2++; //这里会增加int的大小也就是4
    printf("p_2:%x",p_2);
    // printf("p_0:%d\n",*p_0); 这里也会发现不能取出其中的内容
    //这样接下来我们体验使用void*

}
/**
 * void*指针:
 *  不能进行运算和偏移
 *  不可以取出内容
 * 
 *  可以进行赋值
 *  可以接收任何类型的指针而不需要强制转换  -->可以作为一个中间变量负责指针之间的传递
 *  
 */