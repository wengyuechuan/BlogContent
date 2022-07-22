#include<stdio.h>
#include<stdlib.h>
void fun(){
    static int s=0;
    s++;
    printf("%d\n",s);
}
int main(void){
    fun();
    fun();
    fun();
    system("pause");
    return 0;
}