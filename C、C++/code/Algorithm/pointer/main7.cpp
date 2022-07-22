#include<stdio.h>
#include<stdlib.h>
int main(void){
    //申请
    double *p=(double *)malloc(8);
    //使用
    *p=3.14;
    printf("%lf\n",*p);
    //释放
    free(p);
    //置空
    p=NULL;

    //申请
    double *p1=(double*)calloc(sizeof(double),1);
    //使用
    *p1=3.14;
    printf("%lf\n",*p1);
    //释放
    free(p1);
    //置空
    p1=NULL;

    //申请十个double类型大小的内存
    //1.申请
    double *p2=(double *)malloc(sizeof(double)*10);
    //2.使用
    for (size_t i = 0; i < 10; i++)
    {
        p2[i]=10+i;
        printf("%lf\n",p2[i]);
        printf("%lf\n",*(p2+i));//这里两种写法是等效的
    }
    //3.释放
    free(p2);
    //4.置空
    p2=NULL;

    system("pause");
    return 0;    
}
