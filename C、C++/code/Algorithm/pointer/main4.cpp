#include<stdio.h>
#include<stdlib.h>
/**
 * 全局变量：
 *  生命周期：程序开始到结束
 *  作用域：当前项目  当前项目可以具有别的文件
 */
int b;//全局变量

/**
 * 静态全局变量：
 *  生命周期：程序开始到结束
 *  作用域：当前文件 注意是当前文件
 */ 
static int d;//静态全局变量
int main(void){
    /**
     * 局部变量：
     *  生命周期：当前语句块
     *  作用域：当前语句块 （也就是大括号以内）
     */
    int a;//局部变量
    
    /**
     * 静态局部变量：
     *  生命周期：程序开始到结束
     *  作用域：当前语句块
     */
    static int c;//静态局部变量
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",c);
    printf("%d\n",d);
    system("pause");
    return 0;  
}