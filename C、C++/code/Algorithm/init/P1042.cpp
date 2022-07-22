#include<iostream>
#include<math.h>
using namespace std;

int result[65536];
int a,b;
int main(void){
    char s;
    for(int i=1;;i++){
        cin>>s;
        if(s=='E'){
            break;
        }
        if(s=='W'){
            result[i]=1;
        }else{
            result[i]=2;
        }
    }
    for(int i=1;;i++){
        if(result[i]==1){
            a++;
        }
        if(result[i]==2){
            b++;
        }
        if(result[i]==0){
            cout<<a<<":"<<b<<endl<<endl;
            //重置，为了计算21分制做准备
            a=0;
            b=0;
            break;
        }
        if(abs(a-b)>=2){
            if(a>=11 || b>=11){
                cout<<a<<":"<<b<<endl;
                a=0;
                b=0;
            }
        }
    }

    for(int i=1;;i++){
        if(result[i]==1){
            a++;
        }
        if(result[i]==2){
            b++;
        }
        if(result[i]==0){
            cout<<a<<":"<<b<<endl;
            break;
        }
        if(abs(a-b)>=2){
            if(a>=21 || b>=21){
                cout<<a<<":"<<b<<endl;
                a=0;
                b=0;
            }
        }
    }
    return 0;
}
