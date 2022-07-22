#include<stdio.h>
#include<stdlib.h>
int main(void){
    int num=10;
    int *p_0=&num;
    printf("sizeof(num):%d \n",sizeof(num));
    printf("sizeof(p_0):%d \n",sizeof(p_0));
    double val=20.0;
    double*p_1=&val;
    //我们可以看到这里的打印p_1和打印p_0的大小都为8，可以大胆进行猜测，
    //不同的编译器对指针的处理的结果是不一样的，可以看到字节数是不一样的对比老师上课的内容
    printf("sizeof(val):%d \n",sizeof(val));
    printf("sizeof(p_1):%d \n",sizeof(p_1));
    char ch=0;
    char *p_2=&ch;
    printf("sizeof(ch):%d \n",sizeof(ch));
    printf("sizeof(p_2):%d \n",sizeof(p_2));
    printf("%d",*p_0);
    system("pause");
}
/**
 * 1.变量在内存中所占的字节数
 *  所有的指针，不论类型，在内存中所占的字节数都是一样的，
 * 且对于不同的编译器不同，这里的原因应该是不同的编译器分配的虚拟内存空间不同，指针的大小不同，4个字节或者是8个字节
 * 0---FFFFFFFF
 * 0---FFFF
 * 2.指针本身的内存 以及指针指向的内存
 *  指针本身的内存：4个字节  （指针变量只需要存储指向的变量的首地址）
 *  指向的内存：指向的不同类型有不同的字节数
 *  思考：这里也就大概知道了 指针存储首地址，那么其实是根据类型进行移位的，也就是说，如果我们创建的是一个结构体，那么它向后移位的时候，
 *  那么向后移位的大小也肯定是结构体的大小。
 *  那么我们可以做一些骚操作，也就是比如说我们现在用一个int类型变量，然后它是4个字节，那么如何让它指向中间呢，我们只需要找一个short类型的指针，
 *  然后给其赋值，然后向后进行移位，这样就可以指向中间的位置了
 */