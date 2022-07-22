#include<stdio.h>
#include<stdlib.h>
int main(void){
    int len=5;
    //首次分配内存
    int *p=(int *)calloc(sizeof(int ),len);
    int *temp=p;
    int num=0;
    //当前的下标
    int i=0;

    //重复输入
    while (scanf("%d",&num),num!=-1)
    {
        if(i>=len){
            len+=5;
            p=(int *)calloc(sizeof(int),len);
            for(int j=0;j<len;j++){
                p[j]=temp[j];
            }
            free(temp);//先释放之前的结果
            temp=p;
        }
        temp[i++]=num;
    }
    
    for(int i=0;i<len;i++){
        printf("%-3d",p[i]);
    }
    free(p);
    system("pause");
    p=NULL;
    
    return 0;
}