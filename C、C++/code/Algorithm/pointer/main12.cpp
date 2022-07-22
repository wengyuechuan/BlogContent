#include<stdio.h>
#include<stdlib.h>
/**
 * 接下来是函数指针
 * 函数 void test_1()
 * 函数名 test_1
 * 类型 void()   ----->funType
 * 
 * 指针：
 * 本身的类型 指针名
 * 本身的类型：指向的类型*
 * 指向的类型* 指针名
 * void()* pFunc
 * funType* pFunc
 * 
 * void ()*pFunc ===> 返回值类型 (*指针名) (形参表)
 * 返回值类型(*指针名) (形参表) =对应类型函数名
 * 返回值类型( *指针名)(形参表)=&对应类型函数名
 * 
 * 
 */
typedef void funType();

//当然还有一种特殊的方式来定义
typedef void(*pfunType)();  //这里定义的类型其实相当于void()* 类型的重命名，这样的简写方式还是需要记忆一下的

//pfunTypr <====> &funType
//*pfunType <=====>funType
void test_1();
int main(void){
    test_1();
    //最基本的方式当然是这样的
    void(*pFun3)()=&test_1;
    pFun3();
    funType* pFun=&test_1; // 现在指针就指向了函数
    (*pFun)(); //这样就可以执行了
    //但是其实这里的语法并没有那么严格
    funType* pFun1=test_1;
    (*pFun1)();
    funType* pFun2=&test_1;
    pFun2();


    //这里的形式仍然是上面的神奇的形式
    pfunType p=test_1;
    p();
    system("pause");
    return 0;
}
void test_1(){
    printf("Hello world! test_1 is running");
}