#include<iostream>
using namespace std;
int n,na,nb;
int scorea=0,scoreb=0;
int a[205],b[205];//这里是出拳序列
int judge(int a,int b);
/**
 * 对于这个规则当然还是比原本的复杂的多：
 * 0 表示“剪刀”，1 表示“石头”，2 表示“布”，3 表示“蜥蜴人”，4表示“斯波克”
 * 0>2 0>3
 * 1>0 1>3
 * 2>1 2>4
 * 3>2 3>4
 * 4>0 4>1
 * 上面就是全部的规则了 当然这个题肯定不难啊
 * 然后出拳周期这个东西，当然算法就是取余啊，还能有什么捏，就这样吧
 * @return
 */
int main(void){
    cin>>n>>na>>nb;
    for (int i = 0; i < na; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i <nb ; ++i) {
        cin>>b[i];
    }
    for (int i = 0; i <n ; ++i) {
        int result= judge(a[i%na],b[i%nb]);
        if(result==1){
            scorea++;
        }else if(result==-1){
           scoreb ++;
        }
    }
    cout<<scorea<<" "<<scoreb<<endl;
    return 0;
}
int judge(int a,int b){
    if(a==b){
        return 0;
    }
    switch (a) {
        case 0:{
            if(b==2 || b==3){
                return 1;
            }else{
                return -1;
            }
        }
        case 1:{
            if(b==0 || b==3){
                return 1;
            }else{
                return -1;
            }
        }
        case 2:{
            if(b==1 || b==4){
                return 1;
            }else{
                return -1;
            }
        }
        case 3:{
            if(b==2 || b==4){
                return 1;
            }else{
                return -1;
            }
        }
        case 4:{
            if(b==0 || b==1){
                return 1;
            }else{
                return -1;
            }
        }
    }
    return 2; //发生错误了
}