# C、C++指针再总结三

## 一、指针与函数

1. 指针函数：返回值是指针的函数
   示例如下：

   ```cpp
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
       int* p=#
       return p;
   }
   ```
2. 函数指针：指向函数的指针

   这里基本上是知识的盲区，之后我们通过自己定义的函数指针，让函数变成了所谓的“一等公民”，也就是和一般变量一样，我们可以对其进行操作，在嵌入式开发中应用广泛。

   ```cpp
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
   ```

## 二、指针与数组

指针数组：

1. 就是一个数组，访问到元素之后，按照元素类型使用即可，简单的使用如下

   ```cpp
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
       arr_1[1]=#
       arr_1[2]=arr_1[1];
       printf("arr_1[2] =%x\n",arr_1[2]);//打印出指针变量存储的值 也就是地址

       return 0;
   }
   ```
2. 指针数组
