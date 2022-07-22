#include<stdio.h>
#include<stdlib.h>
/**
 * 指针的偏移
 */
int main(void){
    int num=0x12ab34cd;
    int *p=&num;
    char *pch=(char*)p;
    printf("*pch=%x\n",*pch);
    printf("*(pch+1)=%x\n",*(pch+1));
    system("pause");
    return 0;
}