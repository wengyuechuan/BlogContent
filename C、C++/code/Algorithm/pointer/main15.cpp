#include<stdio.h>
#include<stdlib.h>
int main(void){
    double **(*p)[3][4][5];
    printf("%d\n",sizeof(p));
    printf("%d\n",sizeof(*p));
    printf("%d\n",sizeof(**p));
    printf("%d\n",sizeof(***p));
    printf("%d\n",sizeof(****p));
    printf("%d\n",sizeof(*****p));
    printf("%d\n",sizeof(******p));
    double (*p1)[3];
    printf("%d\n",sizeof(p1));
    printf("%d\n",sizeof(*p1));
    system("pause");
    return 0;
}