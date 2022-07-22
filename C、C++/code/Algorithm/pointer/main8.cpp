#include<stdio.h>
#include<stdlib.h>
int main(void){
    //我们如何申请一个类似二维数组的结构
    //这样就实现了分配二维数组的内容
    int len=3;
    int row=4;
    int **pp=(int **)calloc(sizeof(int*),row);
    for (size_t i = 0; i < row; i++)
    {
        pp[i]=(int *)calloc(sizeof(int),len);
    }
    //访问
    for (size_t i = 0; i <row; i++)
    {
        for (size_t j = 0; j <len; j++)
        {
            //当然这里也可以使用偏移调用，当然这里还是十分的复杂
            pp[i][j]=10*i+j;
            printf("%d\n",pp[i][j]);
        }
    }
    
    for (size_t i = 0; i < row; i++)
    {
        free(pp[i]);//释放每一行的内容
        pp[i]=NULL;
    }
    free(pp);//释放这里的内容
    pp=NULL;
    system("pause");
    return 0;
}