#include<stdio.h>
#include<stdlib.h>
void test_1();
int* test_2();
int* test_3();
int main(void){
    test_1();
    int*p2=test_2();
    int* p3=test_3();
    printf("p2=%x\n",p2);
    printf("*p3=%d\n",*p3);//这里会发现p3解引用并不像我们想象的那个样子其中值为10，返回了栈区变量的首地址，因为函数结束之后，栈区释放，num也就不存在了
    //也就是说不能返回指向局部变量的指针，这里对比go语言，go语言可以返回局部变量的指针，因为编译器在处理这种情况的时候，会将我们需要返回的那个变量存储到一个正常的可以访问的区域，这样也就实现了我们可以返回指针的操作
    system("pause");
    return 0;
}
void test_1(){
    printf("void test_1()\n");
}
int* test_2(){//返回值为一个int类型的指针
    return NULL;
}
int* test_3(){
    int num=10;
    int* p=&num;
    return p;
}