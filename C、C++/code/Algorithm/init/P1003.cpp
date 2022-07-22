#include<iostream>
using namespace std;
/**
 * 这里如果直接开一个特别大的数组，利用空间换时间，会出现内存超限的问题，
 * 刷题的过程更多的是跳脱传统思路的过程，思考出更好的方法解决问题才是刷题的关键所在
 */
int a[10006],b[10006],g[10006],k[10006];
int n;
int x,y;//需要进行查找的位置
int main(void){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>g[i]>>k[i];
    }
    cin>>x>>y;
    for(int i=n;i>=1;i--){ //逆序遍历，这样可以更快的找到我们需要的东西
        if(x>=a[i] && y>=b[i] && x<=a[i]+g[i] && y<=b[i]+k[i]){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}